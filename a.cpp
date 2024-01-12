#include <iostream>
#include <cstdlib>
#include <ctime>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    const int arraySize = 1000000;
    int arr[arraySize];

    std::srand(std::time(0));

    for (int i = 0; i < arraySize; i++) {
        arr[i] = std::rand();
    }

    quickSort(arr, 0, arraySize - 1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
