#include "BubbleSort.hpp"

// Bubble Sort Algorithm adapted from https://www.geeksforgeeks.org/bubble-sort/

void BubbleSort::sort(Container *container) {
    int n = container->size();
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
                container->swap(j, j+1);
            }
        }
    }
}
