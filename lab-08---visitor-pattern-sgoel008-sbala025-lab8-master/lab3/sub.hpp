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
	void accept(CountVisitor* visitor) {
	     visitor->visit_sub();
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
	// Take in specific operands
	Base* operand1;
	Base* operand2;
};

#endif //__SUB_HPP__
