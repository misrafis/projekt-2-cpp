#include <iostream>
#include "mergeSort.cpp"
#include "insertionSort.cpp"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int main() {
    int array[10] = {77, 44, 123, 31, 43, 44, 65, 656, 576, 1929};
//    mergeSort(array, 0, 9);
//    insertionSort(array, 10);
    printArray(array, 10);
    return 0;
}
