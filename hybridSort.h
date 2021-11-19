#ifndef SOLUTION_HYBRIDSORT_H
#define SOLUTION_HYBRIDSORT_H

#include "quickSort.h"
#include "insertionSort.h"

void hybrid_insertion_sort(vector<int> &v, int left, int right) {
    for (int j = left; j <= right; j++) {
        int key = v[j];
        int i = j - 1;
        while (i >= left && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

void hybrid_sort(vector<int> &v, int left, int right) {
    if (left < right) {
        if(right-left<=20)
            hybrid_insertion_sort(v,left,right);
        else
        {
            int part = randomized_partition(v, left, right);
            randomized_quick_sort(v, left, part - 1);
            randomized_quick_sort(v, part + 1, right);
        }

    }
}

#endif //SOLUTION_HYBRIDSORT_H
