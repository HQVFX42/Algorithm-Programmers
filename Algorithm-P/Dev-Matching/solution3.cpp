#include <bits/stdc++.h>
using namespace std;

int vis[4][4];

void dfs(vector<vector<int>> grid, int depth, int& answer)
{
    vector<vector<int>> tmp = grid;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tmp[i][j] == grid[i][j]) return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dfs(grid, depth + 1, answer);
        }
    }
}

int solution(vector<vector<int>> grid) 
{
    int answer = -1;



    return answer;
}