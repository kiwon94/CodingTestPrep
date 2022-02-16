#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

vector<string> Split(string str, char delimiter) 
{
	vector<string> internal;
	stringstream ss(str);
	string temp;


	while (getline(ss, temp, delimiter)) 
	{
		internal.push_back(temp);
	}

	return internal;
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    for(int i=0;i<report.size();i++)
    {
        string str=report[i];
        istringstream ss(str);
        vector<string> x;
        string buffer;
        while(getline(ss,buffer,' '))
        {
            x.push_back(buffer);
        }

        for(int i=0;i<x.size();i++)
    {
        map<string,string> m_map;
        auto itr = m_map.find(magazine[i]);
        if (itr == m_map.end())
        {
            m_map.insert({ magazine[i],1 });
        }
        else
        {
            itr->second++;
        }
    }

    }
    vector<int> answer;
    return answer;
}