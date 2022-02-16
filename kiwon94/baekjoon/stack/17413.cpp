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

    stack<char> c_stack;
    string str;
    bool tag=false;
    getline(cin,str);
    for(char a : str)
    {
        if(a==' ')
        {
            if(tag==false)
            {
                while(!c_stack.empty())
                {
                    
                    cout<<c_stack.top();
                    c_stack.pop();
                }
            }
            cout<<a;
        }
 
        else if(a=='<')
        {
            while(!c_stack.empty())
                {
                    cout<<c_stack.top();
                    c_stack.pop();
                }
            tag=true;
            cout<<a;
        }
        else if(a=='>')
        {
            tag=false;
            cout<<a;
        }
        else
        {
            if(tag==true)
                cout<<a;
            else
                c_stack.push(a);
        }
    }
    while(!c_stack.empty())
                {
                    cout<<c_stack.top();
                    c_stack.pop();
                }
    return 0;
}