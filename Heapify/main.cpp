
#include <iostream>
#include "ExMax.cpp"

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int heap[] = { 90, 15, 10, 7, 12, 2, 7, 3 }; // Example of a valid binary heap
    int heapSize = sizeof(heap) / sizeof(heap[0]);

    std::cout << "Original heap: ";
    printArray(heap, heapSize);

    int* newHeap = extractMax(heap, heapSize);

    std::cout << "Heap after extracting max: ";
    printArray(newHeap, heapSize - 1); // The size is reduced by 1 after extraction

    delete[] newHeap; // Don't forget to free the dynamically allocated memory
    return 0;
}