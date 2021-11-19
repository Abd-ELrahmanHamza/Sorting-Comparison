
#include<iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;

void insertion_sort(vector<int> &v) {
    int size = v.size();
    for (int j = 0; j < size; j++) {
        int key = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}
