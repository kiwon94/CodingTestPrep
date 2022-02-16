#include <iostream>
#include <string>
#include <stack>
using namespace std;
int GCD(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;

    

    for(int i=0;i<t;i++)
    {
        long long answer=0;
        int n;
        cin>>n;
        int* num = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>num[j];
        }
        for(int a=0;a<n-1;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                answer+=GCD(num[a],num[b]);
            }
        }
        cout<<answer<<"\n";

    }

    return 0;
}