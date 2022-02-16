#include <bits/stdc++.h>
#include <sstream>
#include <map>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getEventsOrder' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING team1
 *  2. STRING team2
 *  3. STRING_ARRAY events1
 *  4. STRING_ARRAY events2
 */

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

bool is_during(const std::string &str)
{
    return str.find_first_not_of("0123456789") != std::string::npos;
}

vector<string> getEventsOrder(string team1, string team2, vector<string> events1, vector<string> events2) {
    vector<string> event_list;
    multimap<int,string> before_45;
    multimap<int,string> during_45;
    multimap<int,string> after_45;
    vector<string>::iterator iter;
    for(iter=events1.begin();iter!=events1.end();iter++)
    {
        string push_str=team1+' '+(*iter);
        vector<string> words=split((*iter),' ');
        string time_word=words[2];
        if(is_during(time_word))
        {
            vector<string> words2=split(time_word,'+');
            int during_time=stoi(words2[1]);
            during_45.insert({during_time,push_str});
        }
       else
       {
           int tmp_time=stoi(time_word);
           if(tmp_time<=45)
           {
               before_45.insert({tmp_time,push_str});
           }
           else
           {
               after_45.insert({tmp_time,push_str});
           }
       }
    }

    for(iter=events2.begin();iter!=events2.end();iter++)
    {
        string push_str=team2+' '+(*iter);
        vector<string> words=split((*iter),' ');
        string time_word=words[2];
        if(is_during(time_word))
        {
            vector<string> words2=split(time_word,'+');
            int during_time=stoi(words2[1]);
            during_45.insert({during_time,push_str});
        }
       else
       {
           int tmp_time=stoi(time_word);
           if(tmp_time<=45)
           {
               before_45.insert({tmp_time,push_str});
           }
           else
           {
               after_45.insert({tmp_time,push_str});
           }
       }
    }
    map<int, string>::iterator itr;
 
    for (itr = before_45.begin(); itr != before_45.end(); itr++) {
        event_list.push_back(itr->second);
    }
    for (itr = during_45.begin(); itr != during_45.end(); itr++) {
        event_list.push_back(itr->second);
    }
    for (itr = after_45.begin(); itr != after_45.end(); itr++) {
        event_list.push_back(itr->second);
    }
    return event_list;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string team1;
    getline(cin, team1);

    string team2;
    getline(cin, team2);

    string events1_count_temp;
    getline(cin, events1_count_temp);

    int events1_count = stoi(ltrim(rtrim(events1_count_temp)));

    vector<string> events1(events1_count);

    for (int i = 0; i < events1_count; i++) {
        string events1_item;
        getline(cin, events1_item);

        events1[i] = events1_item;
    }

    string events2_count_temp;
    getline(cin, events2_count_temp);

    int events2_count = stoi(ltrim(rtrim(events2_count_temp)));

    vector<string> events2(events2_count);

    for (int i = 0; i < events2_count; i++) {
        string events2_item;
        getline(cin, events2_item);

        events2[i] = events2_item;
    }

    vector<string> result = getEventsOrder(team1, team2, events1, events2);

    for (int i = 0; i < result.size(); i++) {
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
