// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &P, vector<int> &S) {
    // write your code in C++14 (g++ 6.2.0)
    int total_P=0;
    int min_car=0;
    for(int i=0;i<P.size();i++)
    {
        total_P+=P[i];
    }
    sort(S.begin(),S.end(),greater<int>());
    int iter=0;
    while(total_P>0)
    {
        
        total_P-=S[iter];
        min_car++;
        iter++;
        
    }
    return min_car;
}

int main()
{
    vector<int>P;
    vector<int>S;
    for(int i=0;i<3;i++)
    {
        int tmp;
        cin>>tmp;
        P.push_back(tmp);
    }
    for(int i=0;i<3;i++)
    {
        int tmp;
        cin>>tmp;
        S.push_back(tmp);
    }
    int answer=solution(P,S);
    cout<<"answer: "<<answer;
}