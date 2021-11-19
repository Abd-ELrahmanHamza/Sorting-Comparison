
#include<iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;

void selection_sort(vector<int> &v) {
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (v[j] < v[minIndex])
                minIndex = j;
        swap(v[minIndex], v[i]);
    }
}
