#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    int num[26];
    string command;
    cin >> command;
    for(int i=0;i<N;i++)
    {
        cin>>num[i];
    }
    stack<double> calc;
    for(char ch : command)
    {
        if(ch>='A'&&ch<='Z')
        {
            calc.push((double)num[ch-'A']);
        }
        else
        {
            double num1,num2;
            num1=calc.top();
            calc.pop();
            num2=calc.top();
            calc.pop();
            if(ch=='+')
            {
                calc.push(num1+num2);
            }
            else if(ch=='-')
            {
                calc.push(num2-num1);
            }
            else if(ch=='*')
            {
                calc.push(num1*num2);
            }
            else if (ch == '/')
            {
                calc.push(num2/num1);
            }
        }
    }
    cout << fixed << setprecision(2) << calc.top() << '\n';
    return 0;
}

    