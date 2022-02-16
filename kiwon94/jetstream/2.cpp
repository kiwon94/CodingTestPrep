#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    int col_size = grid[0].size();
    int row_size = grid.size();
    bool ***chk_grid = new bool **[row_size];
    for (int i = 0; i < row_size; i++)
    {
        chk_grid[i] = new bool *[col_size];
        for (int j = 0; j < col_size; j++)
        {
            chk_grid[i][j] = new bool[4];
            for (int k = 0; k < 4; k++)
                chk_grid[i][j][k] = false;
        }
    }
    int row = 0;
    int col = 0;
    int dir = 0;
    int cycle_size = 0;
    int root_chk=0;
    while (1)
    {
        if (chk_grid[row][col][dir] == false)
        {
            chk_grid[row][col][dir] = true;
            if (dir == 0)
            {
                col = (col + 1) % col_size;
            }
            else if (dir == 1)
            {
                row = (row + 1) % row_size;
            }
            else if (dir == 2)
            {
                col = (col - 1 + col_size) % col_size;
            }
            else if (dir == 3)
            {
                row = (row - 1 + row_size) % row_size;
            }

            root_chk++;
            cycle_size++;

            if (grid[row][col] == 'L')
            {
                dir = (dir - 1 + 4) % 4;
            }
            else if (grid[row][col] == 'R')
            {  
                dir = (dir + 1) % 4;
            }
        }
        else
        {
            if(cycle_size>0)
            {   
                answer.push_back(cycle_size);
                cycle_size=0;
                if(root_chk==row_size*col_size*4)
                    break;
                for(int i=0;i<row_size;i++)
                {
                    for(int j=0;j<col_size;j++)
                    {
                        for(int k=0;k<4;k++)
                        {
                            if(chk_grid[i][j][k]==false)
                            {
                                row=i;
                                col=j;
                                dir=k;
                                break;
                            }
                        }
                    }
                }
            
                    
            }
            else
             break;
            
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> example;
    example.push_back("RLSRLSRLSRLSRLSRLRLRLSRLLRRLRLSLRLSLRLSRLSRLRLSLRSLRL");
    vector<int> answer=solution(example);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
}