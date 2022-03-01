#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m;	// 장르, 재생횟수
	map<string, vector<pair<int, int>>> mList;	// 장르, 재생횟수, 인덱스
	for (int i = 0; i < genres.size(); i++)
	{
		m[genres[i]] += plays[i];	// 장르별 재생횟수
		mList[genres[i]].push_back({ plays[i], i });	// 장르별 인덱스의 재생횟수
	}
	// 속한 노래가 많이 재생된 장르 먼저 수록
	vector<pair<string, int>> tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(),
		[&](pair<string, int> lhs, pair<string, int> rhs)
		{
			return lhs.second > rhs.second;
		});
	// 장르 내에서 많이 재생된 노래 먼저 수록
	for (auto& i : mList)
	{
		sort(i.second.begin(), i.second.end(),
			[&](pair<int, int> lhs, pair<int, int> rhs)
			{
				return lhs.first > rhs.first;
			});
	}
	// 음악이 2개이상이면 2개까지만 answer에 저장
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