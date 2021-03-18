#include "VectorContainer.hpp"

VectorContainer::VectorContainer() : Container() {}

VectorContainer::VectorContainer(Sort *function) : Container(function) {}

void VectorContainer::set_sort_function(Sort *sort_function)
{
    this->sort_function = sort_function;
}

void VectorContainer::add_element(Base *element)
{
    v.push_back(element);
}

void VectorContainer::print()
{
    for (int unsigned i = 0; i < v.size(); i++)
    {
        cout << v.at(i)->evaluate() << ", ";
    }
    cout << endl;
}

void VectorContainer::sort()
{
    if (sort_function == nullptr)
    {
        throw "Sort function is a null pointer, no sort specified.";
    }
    sort_function->sort(this);
}

void VectorContainer::swap(int i, int j)
{
    Base *tempVar = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = tempVar;
}

Base* VectorContainer::at(int i)
{
    if (i < 0 || i >= v.size())
        return nullptr;

    return v.at(i);
}

int VectorContainer::size()
{
    return v.size();
}


