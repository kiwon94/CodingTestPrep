#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>

using namespace std;
bool num[10000]={false};
int solution(vector<vector<int>> dice) {
    vector<int> index;
    for(int i=0;i<dice.size();i++)
    {
        index.push_back(i);
    }
    do {
        
    } while ( std::next_permutation(index,index+index.size()) );

 
  return 0;
}
    for(int i=0;i<=dice.size();i++)
    {
        for(int j=0;j<6;j++)
        {
            int tmp=dice[i][j];
            if(num[tmp]==false)
                num[tmp]=true;
        }
    }
    
    for(int )
    
    int answer = 0;
    return answer;
}
