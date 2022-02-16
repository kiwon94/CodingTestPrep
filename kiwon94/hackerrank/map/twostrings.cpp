#include <bits/stdc++.h>
#include <set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2) {

    set<char> s1_set;
    set<char> s2_set;
    for(auto it=s1.begin();it!=s1.end();it++)
    {
        s1_set.insert(*it);
    }


    bool chk=false;
    for(auto it=s2.begin();it!=s2.end();it++)
    {
        if(s1_set.find(*it)!=s1_set.end())
        {
            chk=true;
            break;
        }
        
    }
    if(chk==true)
        return "YES";
    else
        return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
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