#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'validateAddresses' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY addresses as parameter.
 */

bool is_digits_v4(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool is_digits_v6(const std::string &str)
{
    return str.find_first_not_of("0123456789abcdef") == std::string::npos;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

bool checkipv4(string addr)
{
    bool val=true;
    auto pos=addr.find('.');
    if(pos==std::string::npos)
    {

        cout<<addr<<": case0: no '.'"<<endl;
        val=false;
        return val;
    }
    else{
        size_t n = std::count(addr.begin(), addr.end(), '.');
        if(n!=3)
        {
            val=false;
            return val;
        }
        vector<string> words=split(addr,'.');
        if(words.size()!=4)
        {
            cout<<addr<<": case1: not 4 words"<<endl;
            val=false;
            return val;
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                cout<<"word: "<<words[i]<<endl;
                if(!is_digits_v4(words[i]))
                {
                    cout<<words[i]<<": case2: not a digit"<<endl;
                    val=false;
                    return val;
                }
                else
                {
                    if(words[i].size()>3)
                    {
                        cout<<words[i]<<": case3: over 3 nums"<<endl;
                        val=false;
                        return val;
                    }
                    else if(words[i].size()==3)
                    {
                        if(words[i][0]=='0')
                        {
                            if(words[i][1]!='0')
                            {
                                cout<<words[i]<<": case4: leading zeros dont allow over 10"<<endl;
                                val=false;
                                return val;
                            }
                            else
                            {
                                int last_digit=words[i][2]-'0';
                                if(last_digit>7)
                                {
                                    cout<<words[i]<<": case5: leading zeros dont allow over 7"<<endl;
                                    val=false;
                                    return val;
                                }
                                else
                                {
    
                                }
                            }
                        }
                        else{
                            int first_digit=words[i][0]-'0';
                            if(first_digit==1)
                            {

                            }
                            else if(first_digit==2)
                            {
                                int second_digit=words[i][1]-'0';
                                int last_digit=words[i][2]-'0';
                                if(second_digit>5)
                                {
                                    cout<<words[i]<<": case6: can't over 25x"<<endl;
                                    val=false;
                                    return val;
                                }
                                else
                                {
                                    if(second_digit==5)
                                    {
                                        if(last_digit>5)
                                        {
                                            cout<<words[i]<<": case7: can't over 255"<<endl;
                                            val=false;
                                            return val;
                                        }
                                        else
                                        {

                                        }
                                    }
                                    else
                                    {

                                    }
                                }
                            }
                            else
                            {
                                cout<<words[i]<<": case8: can't over 2xx"<<endl;
                                val=false;
                                return val;
                            }
                        }
                    }
                    else if(words[i].size()==2)
                    {
                        int first_digit=words[i][0]-'0';
                        if(first_digit==0)
                        {
                            int second_digit=words[i][1]-'0';
                            if(second_digit>7)
                            {
                                cout<<words[i]<<": case9: leading zeros only allowed 01~07"<<endl;
                                val=false;
                                return val;
                            }
                        }
                    }
                }
            }
        }
    }
    return val;
}

bool checkipv6(string addr)
{
    bool val=true;
    auto pos=addr.find(':');
    if(pos==std::string::npos)
    {
        val=false;
        return val;
    }
    else{
        vector<string> words=split(addr,':');
        if(words.size()!=8)
        {
            //cout<<"false"<<endl;
        }
    }
    return val;
}


vector<string> validateAddresses(vector<string> addresses) {
    vector<string> val_chk;
    for(int i=0;i<addresses.size();i++)
    {
        bool ipv4=checkipv4(addresses[i]);
        if(ipv4)
            val_chk.push_back("IPv4");
        else
        {
            bool ipv6=checkipv6(addresses[i]);
            if(ipv6)
                val_chk.push_back("IPv6");
            else
                val_chk.push_back("Neither");
        }
    }
    return val_chk;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string addresses_count_temp;
    getline(cin, addresses_count_temp);

    int addresses_count = stoi(ltrim(rtrim(addresses_count_temp)));

    vector<string> addresses(addresses_count);

    for (int i = 0; i < addresses_count; i++) {
        string addresses_item;
        getline(cin, addresses_item);

        addresses[i] = addresses_item;
    }

    vector<string> result = validateAddresses(addresses);

    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<endl;
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
