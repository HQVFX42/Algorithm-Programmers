#include <bits/stdc++.h>
using namespace std;

int res[11];

void notation(int n, int base)
{
	while (n > 0)
	{
		int tmp = n % base;
		if (tmp != 0)
		{
			res[base] *= tmp;
		}
		n /= base;
	}
}

vector<int> solution(int N) {
	vector<int> answer;

	fill(res, res + 11, 1);
	for (int i = 2; i < 10; i++)
	{
		notation(N, i);
	}
	for (auto& i : res)
	{
		answer.push_back(i);
	}

	map<int, int> m;
	for (int i = 2; i < answer.size(); i++)
	{
		m[i] = answer[i];
	}

	vector<pair<int, int>> vv(m.begin(), m.end());
	sort(vv.begin(), vv.end(), 
		[&](pair<int, int> lhs, pair<int, int> rhs) 
		{
			if (lhs.second == rhs.second) return lhs.first > rhs.first;
			return lhs.second > rhs.second;
		});

	for (auto& i : vv)
	{
		cout << i.first << i.second << ' ';
	}

	vector<int> v;

	v.push_back(vv[0].first);
	v.push_back(vv[0].second);

	return v;
}

int main()
{
	vector<int> v;
	v = solution(10);
	for (auto& i : v)
	{
		//cout << i;
	}
}