#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
//#include "insertionSort.h"
#include "selectionSort.h"
//#include "quickSort.h"
#include "mergeSort.h"
#include "readPrintFile.h"
#include "hybridSort.h"
using namespace std;
using namespace std::chrono;

void printVector(const vector<int> &v) {
    for (int x: v)
        cout << x << " ";
    cout << endl;
}

long long selectionSortTime(vector<int> &data) {
    auto start = high_resolution_clock::now();
    selection_sort(data);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long insertionSortTime(vector<int> &data) {
    auto start = high_resolution_clock::now();
    insertion_sort(data);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long mergeSortTime(vector<int> &data) {
    auto start = high_resolution_clock::now();
    merge_sort(data, 0, (int) data.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long quickSortTime(vector<int> &data) {
    auto start = high_resolution_clock::now();
    randomized_quick_sort(data, 0, (int)data.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}
long long hybridSortTime(vector<int> &data) {
    auto start = high_resolution_clock::now();
    hybrid_sort(data, 0, (int)data.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

long long selectAlgorithm(vector<int> &data, int algorithmNum) {
    long long runningTime = 0;
    switch (algorithmNum) {
        case 0:
            runningTime = selectionSortTime(data);
            break;
        case 1:
            runningTime = insertionSortTime(data);
            break;
        case 2:
            runningTime = mergeSortTime(data);
            break;
        case 3:
            runningTime = quickSortTime(data);
            break;
        case 4:
            runningTime = hybridSortTime(data);
            break;
        default:
            break;
    }
    return runningTime;
}

int main(int argc, char *argv[]) {
    int algorithmNum = argv[1][0] - '0';
    string inputPath(argv[2]);
    string outputPath(argv[3]);
    string timePath(argv[4]);

    vector<int> data;
    readFile(inputPath, data);
    long long runningTime = selectAlgorithm(data, algorithmNum);
    printFile(outputPath, data);
    printTime(timePath,runningTime);
    return 0;
}