
#include <limits.h>
#include<iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;

void merge(vector<int> &v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> vLeft(n1 + 1), vRight(n2 + 1);
    for (int i = 0; i < n1; i++)
        vLeft[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        vRight[j] = v[mid + j + 1];
    vLeft[n1] = INT_MAX;
    vRight[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (vLeft[i] <= vRight[j]) {
            v[k] = vLeft[i];
            i++;
        } else {
            v[k] = vRight[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}
