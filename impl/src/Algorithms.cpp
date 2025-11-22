#include <iostream>
#include <ostream>
#define MAX_ARR_LEN 50
#ifndef ALGO
#define ALGO

void Merge(int *arr, int low, int mid, int high) {
  int i = low, j = mid + 1, k = low;
  int b[MAX_ARR_LEN];
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      b[k] = arr[i];
      i++;
    } else {
      b[k] = arr[j];
      j++;
    }
    k++;
  }
  if (i > mid) {
    for (int l = j; l <= high; l++) {
      b[k] = arr[l];
      k++;
    }
  } else {
    for (int l = i; l <= mid; l++) {
      b[k] = arr[l];
      k++;
    }
  }
  for (int l = low; l <= high; l++) {
    arr[l] = b[l];
  }
}

void MergeSort(int *arr, int low, int high) {
  if (low < high) {
    int mid = (high + low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
  }
}

void print_array(int *arr, int n) {
  std::cout << "[ ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << " ]" << std::endl;
}
#endif // !ALGO
