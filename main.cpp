#include <iostream>
#include <string>
#include "mergeSort.cpp"
#include "insertionSort.cpp"
#include "helperFunctions.cpp"
using namespace std;

int main() {
    vector<string> examples = {"input.txt", "input10.txt", "input1000.txt"};

    for (const auto &item : examples) {
        int arraySize = getArraySize(item);
        int arrayForMergeSort[arraySize];
        int arrayForInsertionSort[arraySize];

        getArrayFromFile(arrayForInsertionSort, item);
        getArrayFromFile(arrayForMergeSort, item);

        mergeSort(arrayForMergeSort,0, arraySize - 1);
        insertionSort(arrayForInsertionSort, arraySize);

        cout << "Sortowanie dla " << item << endl;
        printArray(arrayForMergeSort, arraySize);
        cout << endl;
        printArray(arrayForInsertionSort, arraySize);
        cout << endl;
    }
    return 0;
}
