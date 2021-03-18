#include "BaseFactory.h"

#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"

#include <stack>

Base * parseOperator(char c, Base* op1, Base* op2) {
    if (c == '*')
        return new Mult(op1, op2);
    else if(c == '+')
	    return new Add(op1, op2);
    else if(c == '/')
        return new Div(op1, op2);
    else if(c == '-')
        return new Sub(op1, op2);
    else if(c == '^')
        return new Pow(op1, op2);
    else
	return nullptr;
}

bool isOperator(char c) {
    return c == '*' || c == '-' || c == '+' || c == '/' || c == '^';
}

bool isNumber(char c) {
    return (c >= '0') && (c <= '9');
}

/**
 * Perform a calculation based on the operation passed in and a stack with two operands.
 *
 * This will pop the two operands, and push a new operator base instance onto the stack.
 * @param operandStack The stack with the two operands.
 * @param operation Operation to perform as a character.
 */
void performCalculation(std::stack<Base*>& operandStack, char operation) {
    Base* rightOp = operandStack.top();
    operandStack.pop();

    Base* leftOp = operandStack.top();
    operandStack.pop();

    Base* result = parseOperator(operation, leftOp, rightOp);
    operandStack.push(result);
}

Base * BaseFactory::parse(char **input, int length) {
    char lastOperator = 0;
    std::stack<Base*> operandStack;

    // Loop through all executable arguments starting from 1 (since 0 is name of executable)
    for (int i = 1; i < length; ++i) {
        char* charArray = input[i];

        for (int j = 0; charArray[j] != 0; ++j) {
            char c = charArray[j];

            if (isOperator(c)) {
                // Perform a calculation everytime we hit an operator.
                if (operandStack.size() == 2) {
                    // Perform the previous calculation before setting the next operator
                    performCalculation(operandStack, lastOperator);
                    // Clear last operator for checks below
                    lastOperator = 0;
                }

                // Handle ** as exponent E.g. 5**5 = 5^5
                if (lastOperator && c == '*') {
                    c = '^';
                }

                lastOperator = c;
            } else if (isNumber(c)) {
                // Convert the character to a number
                int val = c - '0';

                // We want to push a new operand onto the stack iff
                // the stack is empty (first number we encounter) or
                // we are encountering the right hand operand. E.g: 5 + 10, we are encountering the 1

                // Stack Size: 2
                if (operandStack.empty() || (lastOperator && operandStack.size() == 1)) {
                    Op *op = new Op(val);
                    operandStack.push(op);
                }
                    // Otherwise, we want to handle a multidigit value.
                else {
                    Base *lastOperand = operandStack.top();
                    operandStack.pop();

                    Op *nextDigit = new Op(lastOperand->evaluate() * 10 + val);
                    // Free up the memory of the previous operand
                    delete lastOperand;
                    // 10
                    operandStack.push(nextDigit);
                }
            }
        }
    }

    // When we hit the end of an equation e.g. 5 + 10, there should be
    // a last operator set and two operands in the stack.
    if (lastOperator && operandStack.size() == 2) {
        performCalculation(operandStack, lastOperator);
    }
    else {
        // Something went wrong!
        return nullptr;
    }

    return operandStack.top();
}
