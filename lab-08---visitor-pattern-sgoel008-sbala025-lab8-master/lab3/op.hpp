#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {
	    this->val = value;
	}
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }

	void accept(CountVisitor* visitor) {
		 visitor->visit_op();
	}


    virtual Iterator* create_iterator() override  {
        return new NullIterator(this);
    }

    virtual Base* get_left() override {
        return nullptr;
    }

    virtual Base* get_right() override {
        return nullptr;
    }

    private:
        double val;
};

#endif //__OP_HPP__
