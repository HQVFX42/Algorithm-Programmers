#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m;	// �帣, ���Ƚ��
	map<string, vector<pair<int, int>>> mList;	// �帣, ���Ƚ��, �ε���
	for (int i = 0; i < genres.size(); i++)
	{
		m[genres[i]] += plays[i];	// �帣�� ���Ƚ��
		mList[genres[i]].push_back({ plays[i], i });	// �帣�� �ε����� ���Ƚ��
	}
	// ���� �뷡�� ���� ����� �帣 ���� ����
	vector<pair<string, int>> tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(),
		[&](pair<string, int> lhs, pair<string, int> rhs)
		{
			return lhs.second > rhs.second;
		});
	// �帣 ������ ���� ����� �뷡 ���� ����
	for (auto& i : mList)
	{
		sort(i.second.begin(), i.second.end(),
			[&](pair<int, int> lhs, pair<int, int> rhs)
			{
				return lhs.first > rhs.first;
			});
	}
	// ������ 2���̻��̸� 2�������� answer�� ����
	for (int i = 0; i < tmp.size(); i++)
	{
		string str = tmp[i].first;
		for (int j = 0; (j < mList[str].size()) && (j < 2); j++)
		{
			answer.push_back(mList[str][j].second);
		}
	}

	return answer;
}