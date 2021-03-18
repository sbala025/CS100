#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "op.hpp"
#include <random>

class Rand : public Base {
	public:
		virtual double evaluate(){
		return rand() % 100;
		}
		virtual std::string stringify(){
		return "";
		}

		void accept(CountVisitor* visitor) {
			visitor->visit_rand();
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

};
#endif //__RAND_HPP__
