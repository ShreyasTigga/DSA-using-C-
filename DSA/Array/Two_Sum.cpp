#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 2, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 5;

    unordered_set<int> seen;
    unordered_set<string> printed; 

    for(int i = 0; i < n; i++) {
        int complement = target - A[i];

        if(seen.find(complement) != seen.end()) {
            int a = min(A[i], complement);
            int b = max(A[i], complement);
            string pairKey = to_string(a) + "," + to_string(b);

            if(printed.find(pairKey) == printed.end()) {
                cout << "(" << a << ", " << b << ")\n";
                printed.insert(pairKey);
            }
        }

        seen.insert(A[i]);
    }

    return 0;
}
