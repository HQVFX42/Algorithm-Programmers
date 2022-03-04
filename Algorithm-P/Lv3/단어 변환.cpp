#include <bits/stdc++.h>
using namespace std;

int vis[55], answer = 55;
// dfs를 이용한 풀이
void dfs(string& begin, string& target, vector<string>& words, int depth)
{	// base condition
	if (begin == target)
	{
		answer = min(answer, depth);
		return;
	}
	for (int i = 0; i < words.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (begin[j] != words[i][j]) cnt++;
			if (cnt > 1) break;
		}
		if (cnt == 1 and vis[i] == false)
		{	// 한 개의 문자만 다르면서 방문 하지 않은 단어라면 탐색
			vis[i] = true;
			dfs(words[i], target, words, depth + 1);
			vis[i] = false;
		}
	}
}
// bfs를 이용한 풀이
void bfs(string& begin, string& target, vector<string>& words)
{
	queue<pair<string, int>> q;	// 단어, 횟수
	q.push({ begin, 0 });	// 시작 지점

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 0; i < words.size(); i++)
		{
			string st = cur.first;
			answer = cur.second;
			int cnt = 0;
			if (vis[i]) continue;	// 이미 방문했다면 패스
			for (int j = 0; j < words[i].size(); j++)
			{
				if (st[j] != words[i][j]) cnt++;	// 다른 문자가 있을 때
				if (cnt > 1) break;
			}
			if (cnt == 1)	// 다른 문자가 하나일때
			{
				if (words[i] == target)
				{
					answer++;
					return;
				}
				vis[i] = true;
				q.push({ words[i], answer + 1 });
			}
		}
	}
	answer = 0;	// 여기까지 도달했으면 target에 도달하지 못한 것
}

int solution(string begin, string target, vector<string> words)
{
	//dfs(begin, target, words, 0);
	//if (answer == 55) return 0;

	bfs(begin, target, words);

	return answer;
}