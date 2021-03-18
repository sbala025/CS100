#include "SelectionSort.hpp"

SelectionSort::SelectionSort() : Sort() {}

void SelectionSort::sort(Container *container)
{
    int n = container->size();
    int i, j, min_index;
    for (i = 0; i< n-1; i++)  
    {
       min_index = i;  
		for (j = i+1; j<n; j++)  
		if ( container->at(j)->evaluate() < container->at(min_index)->evaluate())
            min_index = j;

		if (i != min_index)
            container->swap(i, min_index);
    }

    auto brk = 0;
}

