#pragma once

#include <iostream>
#include <algorithm>

int* heapify(int arr[], int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// If left is a valid index and left child is larger than root
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	// If right is a valid index and left child is larger than root
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	// If largest is not the root, swap root and largest, then heapify largest
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}

	// else root is the largest element
	return arr;
}

int* extractMax(int arr[], int size) {
	
	// If the heap is empty, return original heap
	if (size == 0) {
		return arr;
	}

	// Swap first and last element
	std::swap(arr[0], arr[size - 1]);

	size--;

	// heapify root
	return heapify(arr, size, 0);
	
	
}