#ifndef __ZERO_OP_MOCK_HPP__
#define __ZERO_OP_MOCK_HPP__

#include "base.hpp"

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.0"; }
};

#endif
