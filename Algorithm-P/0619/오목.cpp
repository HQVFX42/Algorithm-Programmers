#include <bits/stdc++.h>
using namespace std;

int dxdy[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
int vis[15][15][4];

int dfs(int x, int y, int dir, vector<vector<int>> board)
{
	int cnt = 1;
	vis[x][y][dir] = 1;
	int nx = x + dxdy[dir][0], ny = y + dxdy[dir][1];

	if (board[x][y] == board[nx][ny]) cnt += dfs(nx, ny, dir, board);
	return cnt;
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (board[i][j] == 0)
			{
				continue;
			}
			for (int dir = 0; dir < 4; dir++)
			{
				if (vis[i][j][dir] == 1) continue;
				if (dfs(i, j, dir, board) == 5)
				{
					answer = 1;
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> v = { 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{2, 1, 1, 2, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 2, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	cout << solution(v);
}