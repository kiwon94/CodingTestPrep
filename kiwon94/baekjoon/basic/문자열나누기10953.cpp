#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> splite(string s){ //splice 함수 구현 npos는 찾는 문자열이 없을때 find(string)==string::npos
	vector<int> v;
	int cutAt = s.find_first_of(",");

	while(cutAt != s.npos){

		v.push_back( stoi(s.substr(0,cutAt)));
		s = s.substr(cutAt+1);
		cutAt = s.find_first_of(",");
	}

	if(s.length() > 0){
		v.push_back( stoi(s.substr(0, cutAt)));
	}

	return v;
}

vector<string> parse(string a, char split)
{
    vector<string> s_list;
    int pos=0;
    int len=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=split)
        {
            len++;
        }
        else
        {
            s_list.push_back(a.substr(pos,len));
            pos=i+1;
            len=0;
        }
    }
    if(len!=0)
        s_list.push_back(a.substr(pos,len));
    return s_list;
}

vector<string> Split(string str, char delimiter) 
{
	vector<string> internal;
	stringstream ss(str);
	string temp;


	while (getline(ss, temp, delimiter)) 
	{
		internal.push_back(temp);
	}

	return internal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin>>T;
    while(T--)
    {
        string S;
        vector<string> numlist;
        cin>>S;
        numlist=Split(S,',');
        int a,b;
        a=stoi(numlist[0]);
        b=stoi(numlist[1]);
        cout<<a+b<<'\n';
    }

}
