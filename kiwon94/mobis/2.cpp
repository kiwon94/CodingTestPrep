#include <string>
#include <vector>

using namespace std;
vector<int> a_stack;
vector<int> b_stack;

vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    a_stack.push_back(0);
    b_stack.push_back(0);
    bool b_start=false;
    bool a_start=false;

    for(int i=0;i<a.size();i++)
    {
        
        string s=a[i];
        int b_index=-1;
        int a_index=-1;
        for(char ch:s)
        {
            if(ch=='b')
            {
                if(b_start==false)
                {
                    b_start=true;
                    b_stack.push_back(0);
                    b_index++;
                }
                else
                {
                    b_stack[b_index]++;
                }
                
            }

            else if(ch=='a')
            {
                if(b_start==true)
                {
                    b_start=false;
                    a_start=true;
                    a_stack.push_back(0);
                    a_index++;
                }
            }

        }
    }bbbbabaabbb
    return answer;
}