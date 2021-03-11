// you can use includes, for example:
#include <algorithm>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // solution using sort 
    int n=A.size();
    if(n==1)
        return A[0];
    else
    {
        sort(A.begin(),A.end());
        int i=0;
        while(i<=n-1)
        {
            if(A[i]==A[i+1])
            {
                i=i+2;
            }
            else
                break;
        }
        return A[i];
    }

    //solution using XOR
    int i, result = 0;
     
    for(i = 0; i < N; i++)
        result ^= A[i];
     
    return result;
    
}
