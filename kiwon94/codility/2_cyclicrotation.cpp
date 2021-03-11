
void reverse(vector<int> &A,int start, int end)
{
    int tmp;
    int i=start;
    int j=end;
    while(i<j)
    {
        tmp=A[i];
        A[i]=A[j];
        A[j]=tmp;
        i++;
        j--;
    }
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    
    int n=A.size();
    
    if(n==0)
        return A;
        
    else
    {
        K%=n;    
        reverse(A,0,n-1);
        reverse(A,0,K-1);
        reverse(A,K,n-1);
        return A;

    }
    

    
}
