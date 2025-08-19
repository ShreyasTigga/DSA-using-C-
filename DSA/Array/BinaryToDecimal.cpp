#include <iostream>
#include<cmath>

int main() {
    
    int val = 0;
    int A[] = {1,0,1,0};
    int sum = 0;
    int k = 0;
    int n = sizeof(A)/sizeof(A[0]);
    for(int i = n; i > -1; i--) {
        val = A[i] * pow(2,k);
        sum = sum + k;
        std::cout << A[i] << " ";
        k++;
    }
    
    std::cout << "\n" << sum;

    return 0;
}