#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer=0;

    string str;
    getline(cin,str);
    char a;
    stack<int> i_stack;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            i_stack.push(i);
        else
        {
            if(i_stack.top()==i-1)
            {
                i_stack.pop();
                answer+=i_stack.size();
            }
            else
            {
                i_stack.pop();
                answer+=1;
            }
        }

    }
    cout<<answer;
}