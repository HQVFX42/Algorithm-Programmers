#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int dxx[] = { 1,-1,1,-1 }, dyy[] = { 1,1,-1,-1 };

bool OOB(int x, int y) { return x < 0 or x > 4 or y < 0 or y > 4; }

bool check(vector<string>& graph)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (graph[i][j] != 'P') continue;

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];
				if (!OOB(nx, ny) and graph[nx][ny] == 'P') return false;
			}
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dxx[dir], ny = j + dyy[dir];
				if (!OOB(nx, ny) and graph[nx][ny] == 'P')
				{
					if (graph[i][ny] != 'X' or graph[nx][j] != 'X') return false;
				}
			}
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + 2 * dx[dir], ny = j + 2 * dy[dir];
				if (!OOB(nx, ny) and graph[nx][ny] == 'P')
				{
					if (graph[i + dx[dir]][j + dy[dir]] != 'X') return false;
				}
			}
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
	for (auto& i : places)
	{
		answer.push_back(check(i));
	}
    return answer;
}