
#include<iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;

int partition(vector<int> &v, int left, int right) {
    int pivot = v[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[right]);
    return i + 1;
}

int randomized_partition(vector<int> &v, int left, int right) {
    int i = left + (rand() % (right - left + 1));
    swap(v[right], v[i]);
    return partition(v, left, right);
}

void randomized_quick_sort(vector<int> &v, int left, int right) {
    if (left < right) {
        int part = randomized_partition(v, left, right);
        randomized_quick_sort(v, left, part - 1);
        randomized_quick_sort(v, part + 1, right);
    }
}
