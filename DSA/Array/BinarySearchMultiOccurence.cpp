#include <iostream>
using namespace std;

int firstOccurrenceOrInsert(int* arr, int n, int target) {
    int begin = 0, end = n - 1;
    int result = n;

    while (begin <= end) {
        int mid = begin + (end - begin) / 2;

        if (arr[mid] >= target) {
            result = mid;  
            end = mid - 1; 
        } 
        else {
            begin = mid + 1;
        }
    }

    return result;
}

int main() {
    int A[] = {1, 3, 5, 7, 9, 11};
    int len = sizeof(A) / sizeof(A[0]);
    int target;

    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << A[i] << " ";
    }
    cout << "\nEnter the target value: ";
    cin >> target;

    int index = firstOccurrenceOrInsert(A, len, target);

    if (index < len && A[index] == target) {
        cout << "First occurrence at index: " << index << "\n";
    } else {
        cout << "Not found. Can be inserted at index: " << index << "\n";
    }

    return 0;
}
