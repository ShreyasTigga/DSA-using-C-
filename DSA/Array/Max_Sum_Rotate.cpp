#include <iostream>
#include <vector>

void max_sum_rotate(int A[], int n)
{
    int x = A[0];
    int y = 0;
    int sum = 0;
    int z = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(A[i] < x)
        {
            y = i;
            break;
        }
        
        x = A[i];
    }
    
    for(int i = y; i < n; i++)
    {
        sum = sum + (A[i] * z);
        z++;
    }
    
    for(int i = 0; i < y; i++)
    {
        sum = sum + (A[i] * z);
        z++;
    }
    
    std::cout << sum;
    std::cout << "\n";
}

int main()
{
    int A[] = {8,3,1,2};
    int n1 = sizeof(A)/sizeof(A[0]);

    max_sum_rotate(A,n1);
        
    int B[] = {1,2,3};
    int n2 = sizeof(B)/sizeof(B[0]);

    max_sum_rotate(B,n2);

    return 0;
}

