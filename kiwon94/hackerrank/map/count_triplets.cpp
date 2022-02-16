#include <bits/stdc++.h>
#include <set>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{

    long triplets = 0;
    multiset<int> arr_set;
    int max_pow = 0;
    bool is_power = true;
    if (r != 1) // r != 1
    {
        for (int i = 0; i < arr.size(); i++)
        {
            is_power = true;
            long pow = 0;
            long num = arr[i];
            if (num != 1)
            {
                while (num != 1)
                {
                    if (num % r == 0)
                    {
                        num /= r;
                        pow++;
                    }
                    else
                    {
                        is_power = false;
                        break;
                    }
                }
                if (is_power == true)
                {
                    if (pow > max_pow)
                        max_pow = pow;
                    arr_set.insert(pow);
                }
            }
            else
            {
                arr_set.insert(0);
            }
        }
    }
    else // r=1 only check 1
    {
        for (int i = 0; i < arr.size(); i++)
        {
            long num = arr[i];
            if (num == 1)
                arr_set.insert(0);
        }
        if (arr_set.count(0) >= 3) // count for 1 for n of 1, there's nC3 cases
        {
            int n = arr_set.count(0);
            triplets += n * (n - 1) * (n - 2) / 6;
        }
    }

    if (max_pow >= 2)
    {
        for (int i = max_pow; i >= 2; i--)
        {
            triplets += arr_set.count(i) * arr_set.count(i - 1) * arr_set.count(i - 2);
        }
    }
    return triplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++)
    {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";
    fout << ans << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
