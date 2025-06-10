
#include <iostream>
#include <vector>
   
    void left_rotate(int A[], int n, int k)
    {
        int B[n];

        if(k >= n)
        {
            k = k % n;
        }
        
        int j = 0;
        
        for(int i = k; i < n; i++)
        {
            B[j] = A[i];
            j++;
        }
        
        for(int i = 0; i < k; i++)
        {
            B[j] = A[i];
            j++;
        }

        for(int i = 0; i < n; i++)
        {
            std::cout << B[i] << ", ";
        }
        std::cout << "\n";
    }

    int main()
    {
        int A[] = {1,3,5,7,9};
        int n = sizeof(A)/sizeof(A[0]);

        int k = 2;
        left_rotate(A,n,k);
        
        k = 3;
        left_rotate(A,n,k);

        k = 4;
        left_rotate(A,n,k);

        return 0;
    }