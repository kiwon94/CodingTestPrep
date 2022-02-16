#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000000;
bool check[MAX + 1];
vector<int> answer;

void erathos()
{
    check[0] = check[1] = true;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (check[i] == false)
        {
            for (int j = i + i; j <= MAX; j += i)
            {
                check[j] = true;
            }
        }
    }
}

int min_prime(int n)
{
    if (n == 1)
        return 1;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (check[i] == false && n % i == 0)
                return i;
        }
    }
}

void function(vector<int>& arr)
{
    int size=arr.size();
    int p=min_prime(size);
    if(p==1)
    {
        answer.push_back(arr[0]);
        return;
    }
    else
    {
        for(int cnt=0;cnt<p;cnt++)
        {
            vector<int> tmp;
            for(int i=0;i<size;i+=p)
            {
                tmp.push_back(arr[cnt+i]);
            }
            function(tmp);
        }
        
    }

}

vector<int> solution(int n)
{
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    function(arr);
    return answer;
}

int main()
{
    int n=12;
    vector<int> a=solution(n);
    return 0;
}