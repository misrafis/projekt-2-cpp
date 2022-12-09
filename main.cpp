#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "mergeSort.cpp"
#include "insertionSort.cpp"
#include "helperFunctions.cpp"
using namespace std;
using namespace chrono;

int *array;

int main() {
    // Aby tablica z danego pliku została posortowana należy w wektorze input_names podać nazwy plików.
    vector<string>inputNames = {};

    for (const auto &inputName : inputNames) {
        int i = 0;
        int arraySize = getArraySize(inputName);
        auto arraySizeString = std::to_string(arraySize);
        cout << arraySize << endl;
        array = new int[arraySize];

        getArrayFromFile(array, inputName);

        auto mergeSortStart = high_resolution_clock::now();
        mergeSort(array, 0, arraySize - 1);
        auto mergeSortStop = high_resolution_clock::now();

        getArrayFromFile(array, inputName);

        auto insertionSortStart = high_resolution_clock::now();
        insertionSort(array, arraySize);
        auto insertionSortStop = high_resolution_clock::now();

        auto durationMergeSort = duration_cast<milliseconds>(mergeSortStop - mergeSortStart).count();
        auto durationInsertionSort = duration_cast<milliseconds>(insertionSortStop - insertionSortStart).count();

        writeArrayToFile(array, arraySize, durationMergeSort, "mergeSort", "output" + arraySizeString + "mergeSort.txt");
        writeArrayToFile(array, arraySize, durationInsertionSort, "insertionSort", "output" + arraySizeString + "insertionSort.txt");

        cout << "Sortowanie przez scalanie dla tablicy o " << arraySize << " elementow - czas: " << durationMergeSort << endl;
        cout << endl;
        cout << "Sortowanie przez wstawianiedla tablicy o " << arraySize << " elementow - czas: " << durationInsertionSort << endl;
        cout << endl;
        delete[] array;
    }
    return 0;
}
