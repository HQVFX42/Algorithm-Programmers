#include <bits/stdc++.h>
using namespace std;

int vis[11111];

void dfs(vector<vector<string>> tickets, vector<string>& answer, int cnt, string cur, vector<string> tmp)
{
	tmp.push_back(cur);
	if (cnt == tickets.size() && answer.empty())
	{	// 가능한 경로가 2개 이상일 경우 한번만 
		answer = tmp;
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == cur and vis[i] == false)
		{
			vis[i] = true;
			dfs(tickets, answer, cnt + 1, tickets[i][1], tmp);
			vis[i] = false;
		}
	}
	tmp.pop_back();
}

void bfs(vector<vector<string>> tickets, vector<string>& answer, string cur, vector<string> tmp)
{
	queue<string> q;
	q.push(cur);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 0; i < tickets.size(); i++)
		{
			string nxt = tickets[i][1];
			if (vis[i] and tickets[i][0] == cur) continue;
			answer.push_back(nxt);
			vis[i] = 1;
			q.push(nxt);
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;

	sort(tickets.begin(), tickets.end());
	vector<string> tmp;
	//dfs(tickets, answer, 0, "ICN", tmp);
	bfs(tickets, answer, "ICN", tmp);

	return answer;
}