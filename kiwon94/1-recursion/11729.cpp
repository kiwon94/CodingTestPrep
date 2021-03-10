#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
stringstream ss;
//vector<string> m;
vector<pair<int,int>> v;
void hanoi(int N, int start, int via, int end)
{
    if(N==1)
    {
        //ss << start << " " << end << endl;
        //m.push_back(ss.str());
        //ss.str("");
        v.push_back(make_pair(start,end));
        return;
    }
    hanoi(N-1,start,end,via);
    //ss << start << " " << end << endl;
    //m.push_back(ss.str());
    //ss.str("");
    v.push_back(make_pair(start,end));
    hanoi(N-1,via,start,end);
}

int main(){
    int N;
    cin>>N;
    hanoi(N,1,2,3);
    //cout<<m.size()<<endl;
    cout<<v.size()<<endl;
    //for(int i=0;i<m.size();i++)
    //{
    //    cout<<m[i]<<endl;
    //}
    for(auto i:v)
    {
        printf("%d %d\n",i.first,i.second);
    }
    return 0;
}