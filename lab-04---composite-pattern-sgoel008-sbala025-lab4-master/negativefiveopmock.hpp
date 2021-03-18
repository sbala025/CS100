#ifndef __NEGATIVE_FIVE_OP_MOCK_HPP__
#define __NEGATIVE_FIVE_OP_MOCK_HPP__

#include "base.hpp"

class NegativeFiveOpMock: public Base {
    public:
        NegativeFiveOpMock() { };

        virtual double evaluate() { return -5.0; }
        virtual std::string stringify() { return "-5.0"; }
};

#endif
