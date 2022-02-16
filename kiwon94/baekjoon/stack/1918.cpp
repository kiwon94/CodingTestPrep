#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string command;
    cin >> command;
    stack<char> calc;
    for(char ch : command)
    {
        if(ch>='A'&&ch<='Z')
        {
            cout<<ch;
        }
        else
        {
            if(ch=='+'||ch=='-')
            {
                if(calc.empty())
                   calc.push(ch);
                else
                {
                    while(calc.top()!='(')
                    {
                        cout<<calc.top();
                        calc.pop();
                        if(calc.empty())
                            break;
                    }
                    calc.push(ch);
                } 
                
            }

            else if(ch=='*'||ch=='/')
            {
                if(calc.empty())
                   calc.push(ch);
                else
                {
                    if(calc.top()=='*'||calc.top()=='/')
                    {
                        cout<<calc.top();
                        calc.pop();
                    }
                    calc.push(ch);
                }
                
            }

            else if(ch=='(')
            {
                calc.push(ch);
            }

            else if(ch==')')
            {
                while(calc.top()!='(')
                {
                    cout<<calc.top();
                    calc.pop();
                }
                calc.pop();
            }

        }
    }

    while(!calc.empty())
    {
        cout<<calc.top();
        calc.pop();
    }

    return 0;
}
