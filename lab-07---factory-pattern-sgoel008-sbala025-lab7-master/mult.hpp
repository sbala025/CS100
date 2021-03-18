#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* op1, Base* op2) : Base() {
	     this->operand1 = op1;
	     this->operand2 = op2;   	
	}
        
	virtual double evaluate() {
	     return operand1->evaluate() * operand2->evaluate();
	}

        virtual std::string stringify() {
	     return operand1->stringify() + " * " + operand2->stringify();
	}

    private:
	// Take in specific operands
	Base* operand1;
	Base* operand2;
};

#endif //__MULT_HPP__
