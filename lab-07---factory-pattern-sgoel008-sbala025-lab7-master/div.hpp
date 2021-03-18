#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    public:
        Div(Base* val1, Base* val2) : Base() {
	     this->operand1 = val1;
	     this->operand2 = val2;   	
	}

	virtual double evaluate() {
	     return operand1->evaluate() / operand2->evaluate();
	}

        virtual std::string stringify() {
	     return operand1->stringify() + " / " + operand2->stringify();
	}

    private:
	Base* operand1;
	Base* operand2;
};
#endif //__DIV_HPP__

