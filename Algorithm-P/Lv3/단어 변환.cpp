#include <bits/stdc++.h>
using namespace std;

int vis[55], answer = 55;
// dfs�� �̿��� Ǯ��
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
		{	// �� ���� ���ڸ� �ٸ��鼭 �湮 ���� ���� �ܾ��� Ž��
			vis[i] = true;
			dfs(words[i], target, words, depth + 1);
			vis[i] = false;
		}
	}
}
// bfs�� �̿��� Ǯ��
void bfs(string& begin, string& target, vector<string>& words)
{
	queue<pair<string, int>> q;	// �ܾ�, Ƚ��
	q.push({ begin, 0 });	// ���� ����

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 0; i < words.size(); i++)
		{
			string st = cur.first;
			answer = cur.second;
			int cnt = 0;
			if (vis[i]) continue;	// �̹� �湮�ߴٸ� �н�
			for (int j = 0; j < words[i].size(); j++)
			{
				if (st[j] != words[i][j]) cnt++;	// �ٸ� ���ڰ� ���� ��
				if (cnt > 1) break;
			}
			if (cnt == 1)	// �ٸ� ���ڰ� �ϳ��϶�
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
	answer = 0;	// ������� ���������� target�� �������� ���� ��
}

int solution(string begin, string target, vector<string> words)
{
	//dfs(begin, target, words, 0);
	//if (answer == 55) return 0;

	bfs(begin, target, words);

	return answer;
}