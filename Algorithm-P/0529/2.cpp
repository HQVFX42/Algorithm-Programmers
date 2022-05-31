#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> balance, vector<vector<int>> transaction, vector<int> abnormal)
{
	vector<int> answer;

	map<int, map<int, int>> m;    // {user,{info, money}}
	int user = balance.size();
	for (int i = 0; i < user; i++)
	{
		for (int j = 0; j < user; j++)
		{
			m[i][j] = balance[j];
		}
	}
	int tsz = transaction.size();
	for (int i = 0; i < user; i++)
	{
		for (int j = 0; j < tsz; j++)
		{
			int from = transaction[j][0] - 1;
			int to = transaction[j][1] - 1;
			int num = transaction[j][2];
			m[i][from] -= num;
			m[i][to] += num;
		}
	}
	int asz = abnormal.size();
	for (int i = 0; i < user; i++)
	{
		for (int j = 0; j < asz; j++)
		{
			int del = abnormal[j] - 1;
			m[i][del] = 0;
		}
	}
	for (int i = 0; i < m.size(); i++)
	{
		int sum = 0;
		sum += m[0][i];
		answer.push_back(sum);
	}

	return answer;
}

int main()
{
	vector<int> b = { 30,30,30,30 };
	vector<vector<int>> t = { {1,2,10},{2,3,20}, {3,4,5}, {3,4,30} };
	vector<int> a = { 1 };
	vector<int> ans = solution(b, t, a);
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
}