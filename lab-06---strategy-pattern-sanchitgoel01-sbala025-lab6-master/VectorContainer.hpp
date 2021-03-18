#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sort.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class VectorContainer : public Container
{
private:
    std::vector<Base *> v;

public:
    VectorContainer();

    VectorContainer(Sort *function);

    void set_sort_function(Sort *sort_function);

    virtual void add_element(Base *element);

    virtual void print();

    virtual void sort();

    virtual void swap(int i, int j);

    virtual Base *at(int i);

    virtual int size();
};

#endif //__VECTORCONTAINER_HPP__
