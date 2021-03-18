#include "listcontainer.hpp"
#include <iostream>
#include <list>

void ListContainer::set_sort_function(Sort* sort_function) {
    this->sort_function = sort_function;
};

// Virtual Functions
void ListContainer::add_element(Base* element) {
    this->backingList.push_back(element);
};

void ListContainer::print() {
    for (Base* elem : backingList) {
        std::cout << elem->stringify() << '\n';
    }
};

void ListContainer::sort() {
    if (!this->sort_function)
        throw std::runtime_error("No sort function set!");

    this->sort_function->sort(this);
};

// Functions needed for sorting
void ListContainer::swap(int i, int j) {
    auto it1 = backingList.begin();
    auto it2 = backingList.begin();

    std::advance(it1, i);
    std::advance(it2, j);

    std::swap(*it1, *it2);
};

Base* ListContainer::at(int i) {
    if (i < 0 || i >= backingList.size())
    return nullptr;

    auto it = backingList.begin();
    std::advance(it, i);

    return *it;
};

int ListContainer::size() {
    return this->backingList.size();
};
