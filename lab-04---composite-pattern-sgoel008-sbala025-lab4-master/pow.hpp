#ifndef __POW_HPP__
#define __POW_HPP__

#include <string>
#include <math.h>
#include <random>

class Pow : public Base {
    public:
        /* Constructors */
        Pow(Base* op1, Base* op2) :Base () {
	     this->operand1 = op1;
	     this->operand2 = op2; 
	 };

        /* Pure Virtual Functions */
        virtual double evaluate(){
		return pow(operand1->evaluate(), operand2->evaluate());
	}

        virtual std::string stringify(){
		return operand1->stringify() + " ** " + operand2->stringify();
	}
   private:
	Base* operand1;
	Base* operand2;
};

#endif //__POW_HPP__
