#ifndef SOLUTION_HYBRIDSORT_H
#define SOLUTION_HYBRIDSORT_H


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
int hybrid_partition(vector<int> &v, int left, int right) {
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

int hybrid_randomized_partition(vector<int> &v, int left, int right) {
    int i = left + (rand() % (right - left + 1));
    swap(v[right], v[i]);
    return hybrid_partition(v, left, right);
}
void hybrid_sort(vector<int> &v, int left, int right) {
    if (left < right) {
        if(right-left<=20)
            hybrid_insertion_sort(v,left,right);
        else
        {
            int part = hybrid_randomized_partition(v, left, right);
            hybrid_sort(v, left, part - 1);
            hybrid_sort(v, part + 1, right);
        }

    }
}

#endif //SOLUTION_HYBRIDSORT_H
