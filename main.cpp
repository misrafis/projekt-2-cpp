#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "mergeSort.cpp"
#include "insertionSort.cpp"
#include "helperFunctions.cpp"
using namespace std;
using namespace chrono;

int main() {
    vector<string> examples = {};

    for (const auto &item : examples) {
        int arraySize = getArraySize(item);
        int array[arraySize];

        getArrayFromFile(array, item);

        auto mergeSortStart = high_resolution_clock::now();
        mergeSort(array,0, arraySize - 1);
        auto mergeSortStop = high_resolution_clock::now();

        getArrayFromFile(array, item);

        auto insertionSortStart = high_resolution_clock::now();
        insertionSort(array, arraySize);
        auto insertionSortStop = high_resolution_clock::now();

        auto durationMergeSort = duration_cast<milliseconds>(mergeSortStop - mergeSortStart);
        auto durationInsertionSort = duration_cast<milliseconds>(insertionSortStop - insertionSortStart);

        cout << "Sortowanie przez scalanie dla tablicy o "<< arraySize <<" elementow - czas: " << durationMergeSort.count() << endl;
//        printArray(arrayForMergeSort, arraySize);
        cout << endl;
        cout << "Sortowanie przez wstawianiedla tablicy o "<< arraySize <<" elementow - czas: " << durationInsertionSort.count() << endl;
//        printArray(arrayForInsertionSort, arraySize);
        cout << endl;
    }
    return 0;
}
