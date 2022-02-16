#include <string>
#include <vector>

using namespace std;

int low_cnt(int index, vector<int> arr)
{
    if(index==0)
        return 1+arr[index];
    else
        return arr[index]-arr[index-1];
}

int high_cnt(int index, vector<int> arr, int total_size)
{
    if(index==arr.size()-1)
        return total_size-arr[index];
    else
        return arr[index+1]-arr[index];
}

int solution(vector<int> student, int k) {

    int answer = 0;
    vector<int> j_arr;
    for(int i=0;i<student.size();i++)
    {
        if(student[i]==1)
            j_arr.push_back(i);
    }
    int j_size=j_arr.size();
    int t_size=student.size();
    if(j_size<k)
        answer=0;
    else
    {
        for(int i=0;i<=j_size-k;i++)
        {
            int low=low_cnt(i,j_arr);
            int high=high_cnt(i+k-1,j_arr,t_size);
            answer+=low*high;
        }
    }
    return answer;
}
int main()
{
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    int k=1;
    int answer=solution(a,k);
}