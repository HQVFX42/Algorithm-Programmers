#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> card)
{
	vector<int> answer;

	int sz = card.size();
	map<int, int> m;
	for (int i = 0; i < sz; i++)
	{
		m[card[i]]++;
	}
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] == 1)
		{
			answer.push_back(m[i]);
		}
	}
}