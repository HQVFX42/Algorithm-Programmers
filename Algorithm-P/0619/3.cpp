#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1,-1,0,0,0,0 }, dy[] = { 0,0,1,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
int dist[77][77][77];
queue<tuple<int, int, int>> q;

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

int solution(vector<vector<string>> map3d)
{
	int answer = 0;

	int h = map3d.size();
	int n = map3d[0].size();
	int m = map3d[0][0].length();
	int ex = 0, ey = 0, ez = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map3d[i][j][k] == 'S') { q.push({ j,k,i }); }
				if (map3d[i][j][k] == 'O') { dist[j][k][i] = -1; }
				if (map3d[i][j][k] == 'E') { dist[j][k][i] = -1; ex = j, ey = k, ez = i; }
			}
		}
	}

	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir], nz = z + dz[dir];
			if (OOB(nx, ny, n, m) or dist[nx][ny][nz] >= 0 or map3d[nz][nx][ny] == 'X') continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == -1)
				{
					answer = -1;
					return answer;
				}
				answer = dist[ex][ey][ez];
				cout << dist[j][k][i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return answer;
}

int main()
{
	vector<vector<string>> v1 = { {"XXXXX", "OOSXO", "OOXOO"}, {"XEOOO", "OXXXO", "OOOOX"} };
	vector<vector<string>> v2 = {{"OOOOO", "OOOOO", "OOEOO", "OOOOO", "OOOOO"}, {"OOOOO", "OXXXO", "OXXXO", "OXXXO", "OOOOO"}, {"OOOOO", "OOOOO", "OOSOO", "OOOOO", "OOOOO"}};
	cout << solution(v2);
}