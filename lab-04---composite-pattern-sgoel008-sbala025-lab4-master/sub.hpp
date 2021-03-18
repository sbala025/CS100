#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    public:
        Sub(Base* op1, Base* op2) : Base() {
	     this->operand1 = op1;
	     this->operand2 = op2;   	
	}
        
	virtual double evaluate() {
	     return operand1->evaluate() - operand2->evaluate();
	}

        virtual std::string stringify() {
	     return operand1->stringify() + " - " + operand2->stringify();
	}

    private:
	// Take in specific operands
	Base* operand1;
	Base* operand2;
};

#endif //__SUB_HPP__
