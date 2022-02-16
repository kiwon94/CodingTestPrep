#include <string>
#include <vector>

using namespace std;

string solution(vector<string> research, int n, int k) {

    int issue[26]={};
    string answer="";

    int r_size=research.size();

    int** chk = new int*[26];
    for(int i=0;i<26;i++)
    {
        chk[i]=new int[r_size]{};
    }

    for(int i=0;i<r_size;i++)
    {
        string s=research[i];
        int s_size=s.size();
        for(int j=0;j<s_size;j++)
        {
            if(s[j]>=97&&s[j]<=122)
            {
                int pos=s[j]-97;
                chk[pos][i]+=1;
            }
        }
    }
    
    if(r_size<n)
        answer="None";
    
    else
    {
        for(int idx=0;idx<26;idx++)
        {
            for(int i=0;i<=r_size-n;i++)
            {
                int d_cnt=chk[idx][i];
                if(d_cnt>=k)
                {
                    int t_cnt=d_cnt;
                    int iter=1;
                    while(iter<=n-1)
                    {
                        int tmp_cnt=chk[idx][i+iter];
                        if(tmp_cnt>=k)
                        {
                            t_cnt+=tmp_cnt;
                            iter++;
                        }
                        else
                            break;

                    }

                    if(iter==n)
                    {
                        if(t_cnt>=(2*n*k))
                            issue[idx]++;
                    }
                }
            }
        }
        int max=0;
        char ans;
        for(int idx=0;idx<26;idx++)
        {
            if(issue[idx]>max)
            {
                max=issue[idx];
                ans=char(idx+97);
            }    
        }
        if(max!=0)
            answer.push_back(ans);
        else
            answer="None";
        
        
    }

    return answer;
}

int main()
{
    vector<string> a;
    int n=1,k=1;
    a.push_back("ab");
    a.push_back("ab");


    string answer=solution(a,n,k);

}