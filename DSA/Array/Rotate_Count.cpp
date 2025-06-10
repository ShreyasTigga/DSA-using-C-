#include <iostream>
#include <vector>
   
    void rotate_count(int A[], int n)
    {
        int x = A[0];
        int y = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(A[i] < x)
            {
                y = i;
                break;
            }

            x = A[i];

        }
        
        std::cout << y;
        std::cout << "\n";
    }

    int main()
    {
        int A[] = {15,18,2,3,6,7};
        int n1 = sizeof(A)/sizeof(A[0]);

        rotate_count(A,n1);
        
        int B[] = {7,9,11,12,5};
        int n2 = sizeof(B)/sizeof(B[0]);

        rotate_count(B,n2);
        
        int C[] = {7,9,11,12,15};
        int n3 = sizeof(C)/sizeof(C[0]);

        rotate_count(C,n3);

        return 0;
    }