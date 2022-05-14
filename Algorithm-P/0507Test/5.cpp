#include <bits/stdc++.h>
using namespace std;

void ShiftRow(vector<vector<int>>& rc)
{
	vector<vector<int>> tmp(rc);
	int r = rc.size();
	int c = rc[0].size();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == r - 1)
			{
				tmp[0][j] = rc[i][j];
			}
			else
			{
				tmp[i + 1][j] = rc[i][j];
			}
		}
	}
	rc.swap(tmp);
}
void Rotate(vector<vector<int>>& rc)
{
	vector<vector<int>> tmp(rc);
	int x = 0;
	int y = 0;
	int xx = rc.size() - 1;
	int yy = rc[0].size() - 1;

	for (int i = x; i < xx; i++)
	{	// l
		tmp[i][y] = rc[i + 1][y];
	}
	for (int i = y; i < yy; i++)
	{	// b
		tmp[xx][i] = rc[xx][i + 1];
	}
	for (int i = xx; i > x; i--)
	{	// r
		tmp[i][yy] = rc[i - 1][yy];
	}
	for (int i = yy; i > y; i--)
	{	// t
		tmp[x][i] = rc[x][i - 1];
	}

	rc.swap(tmp);
}
void print(vector<vector<int>> rc)
{
	for (int i = 0; i < rc.size(); i++)
	{
		for (auto& p : rc[i])
		{
			cout << p << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations)
{
	vector<vector<int>> answer;

	int row = rc.size();
	int column = rc[0].size();
	
	for (auto& i : operations)
	{
		if (i == "ShiftRow")
		{
			ShiftRow(rc);
			//print(rc);
		}
		else
		{
			Rotate(rc);
			//print(rc);
		}
	}
	answer = rc;

	return answer;
}

int main()
{
	vector<vector<int>> rc = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<string> op = { "ShiftRow","Rotate", "ShiftRow","Rotate"};

	vector<vector<int>> tt;
	/*for (int i = 0; i < 50000; i++)
	{
		for (int j = 0; j < 50000; j++)
		{
			tt.push_back({ i,j });
		}
	}*/
	vector<string> t;
	for (int i = 0; i < 99999; i++)
	{
		t.push_back("Rotate");
	}
	vector<vector<int>> ans;
	ans = solution(rc, op);
	print(ans);
}