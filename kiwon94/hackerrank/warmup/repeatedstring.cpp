#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING sa
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {

    long long s_len=s.size();
    long long total_cnt=0;
    if(s_len>n)
    {
        long long iter=0;
        while(iter<n)
        {
            if(s[iter]=='a')
            {
                total_cnt++;
            }
            iter++;
        }
    }
    else
    {
        long long iter=0;
        cout<<s_len<<endl;
        while(iter<s_len)
        {
            if(s[iter]=='a')
            {
                total_cnt++;
            }
            iter++;
        }
        
        long long mlt=n/s_len;
        total_cnt*=mlt;
        long long res=n-s_len*mlt;
        iter=0;
        while(iter<res)
        {
            if(s[iter]=='a')
            {
                total_cnt++;
            }
            iter++;
        }
    }

    return total_cnt;

}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long long n = stol(ltrim(rtrim(n_temp)));

    long long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();
    cout<<result<<endl;
    return 0;
}


