#include <iostream>

int binarySearch(int* arr, int begin, int end, int target) {
    if (end >= begin) {
        int mid = begin + (end - begin) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (target < arr[mid]) {
            return binarySearch(arr, begin, mid - 1, target);
        }
        else {
            return binarySearch(arr, mid + 1, end, target);
        }
    }
    return begin;
}

int main() {
    int A[] = {1, 3, 5, 7, 9, 11};
    int len = sizeof(A) / sizeof(A[0]);
    int target;

    for (int i = 0; i < len; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\nEnter the target value : ";
    std::cin >> target;

    int index = binarySearch(A, 0, len - 1, target);
    std::cout << "Value found at or will be at index : " << index << "\n";

    return 0;
}
