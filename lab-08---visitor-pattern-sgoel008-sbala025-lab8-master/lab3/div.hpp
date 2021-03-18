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
	void accept(CountVisitor* visitor) {
	     visitor->visit_div();
	}

    virtual Iterator* create_iterator() override  {
        return new BinaryIterator(this);
    }

    virtual Base* get_left() override {
        return this->operand1;
    }

    virtual Base* get_right() override {
        return this->operand2;
    }

    private:
	Base* operand1;
	Base* operand2;
};
#endif //__DIV_HPP__

