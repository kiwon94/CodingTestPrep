#include <string>
#include <vector>
#include <stack>

using namespace std;

//bool is_start=true;
//bool is_end=false;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    
    int** map = new int*[n+1];
    bool** is_able = new bool*[n+1];
    bool* is_trap = new bool[n+1];
    
    for(int i=0;i<n+1;i++)
    {
        map[i]= new int[n+1];
        is_able[i] = new bool[n+1];
    }
    
    for(int y=1;y<n+1;y++)
    {
        for(int x=1;x<n+1;x++)
        {
            map[y][x]=-1;
            is_able[y][x]=false;
        }
        is_trap[y]=false;
    }
    
    for(int i=0;roads.size();i++)
    {
        int y=roads[i][0];
        int x=roads[i][1];
        int cost=roads[i][2];
        map[y][x]=cost;
        map[x][y]=cost;
        is_able[y][x]=true;
    }
    for(int i=0;i<traps.size();i++)
    {
        int trap=traps[i];
        is_trap[trap]=true;
    }
    
    stack <int> point_s;
    stack <int> time_s;
    point_s.push(start);
    time_s.push(0);

    vector<int> score_list;
    while(!point_s.empty())
    {
        
        int start_p=point_s.top();
        int start_time=time_s.top();
        point_s.pop();
        time_s.pop();
        for(int i=1;i<=n;i++)
        {
            if(is_able[start_p][i]==true)
            {
                if(i==end)
                {
                    int elapsed_time=start_time+map[start_p][end];
                    score_list.push_back(elapsed_time);
                }
                else
                {
                    point_s.push(i);
                    time_s.push(start_time+map[start_p][i]);
                    if(is_trap[i]==true)
                    {
                        for(int j=1;j<=n;j++)
                        {
                            if(is_able[i][j]==true)
                            {
                                is_able[i][j]=false;
                            }
                            else
                            {
                                if(map[i][j]!=-1)
                                {
                                    is_able[i][j]=true;
                                }
                            }

                            if(is_able[j][i]==true)
                            {
                                is_able[j][i]=false;
                            }

                            else
                            {
                                if(map[j][i]!=-1)
                                {
                                    is_able[j][i]=true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    
    int answer = 0;
    return answer;
}