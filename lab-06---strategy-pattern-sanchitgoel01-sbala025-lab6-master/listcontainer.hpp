#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include "container.hpp"
#include <list>

class ListContainer : public Container {

    public:
        ListContainer() : Container() { };
        ListContainer(Sort* function) : Container(function) { };

        void set_sort_function(Sort* sort_function);

        // Virtual Functions
        void add_element(Base* element) override;

        void print() override;

        void sort() override;

        // Functions needed for sorting
        void swap(int i, int j) override;

        Base* at(int i) override;

        int size() override;

    private:
	    std::list<Base*> backingList;
};

#endif //  __LISTCONTAINER_HPP__
