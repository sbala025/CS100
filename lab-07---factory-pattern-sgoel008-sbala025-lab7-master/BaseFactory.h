#ifndef CS100_LAB7_BASEFACTORY_H
#define CS100_LAB7_BASEFACTORY_H

#include "base.hpp"

class BaseFactory {
    public:
        Base* parse(char** input, int length);
};


#endif //CS100_LAB7_BASEFACTORY_H
