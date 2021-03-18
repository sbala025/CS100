#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "sort.hpp"

class BubbleSort : public Sort {
    public:
        BubbleSort() : Sort() {}

        void sort(Container *container) override;
};


#endif //__BUBBLESORT_HPP__
