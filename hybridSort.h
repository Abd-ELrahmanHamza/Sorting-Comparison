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
    while (left < right) {
        if (right - left < 10) {
            hybrid_insertion_sort(v, left, right);
            break;
        } else {
            int pivot = randomized_partition(v, left, right);
            if (pivot - left < right - pivot) {
                hybrid_insertion_sort(v, left, pivot - 1);
                left = pivot + 1;
            } else {
                hybrid_insertion_sort(v, pivot + 1, right);
                right = pivot - 1;
            }
        }
    }
}

#endif //SOLUTION_HYBRIDSORT_H
