#include <bits/stdc++.h>
using namespace std;

int vis[1111][1111][4];	// 가로 세로 양쪽 대각선
int dx[8] = { 1,1,1,0,-1,-1,-1,0 }, dy[8] = { 1,0,-1,-1,-1,0,1,1 };
queue<pair<int, int>> q;

int solution(int h, int w, int n, vector<string> board)
{
	int answer = -1;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == '1' && vis[i][j] == 0)
			{
				q.push({ i,j });
				vis[i][j][0] = 1;
				vis[i][j][1] = 1;
				vis[i][j][2] = 1;
				vis[i][j][3] = 1;
				continue;
			}
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		int x, y, status;
		tie(x, y) = q.front();
		q.pop();
		for (int dir = 0; dir < 8; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 or nx > h or ny < 0 or ny > w) continue;
			if (vis[nx][ny] && board[nx][ny] != 0)
			{
				vis[nx][ny][status] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	if (cnt == n) answer = cnt;

	return answer;
}

int main()
{
	vector<string> board = { "11111","11111","11111","11111","11111" };
	cout << solution(5, 5, 5, board);
}