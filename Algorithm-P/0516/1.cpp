#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> v)
{
	int answer = 0x0f0f0f0f;

	int tmp = 0;
	vector<int> vv;
	for (int i = 0; i <= n; i++)
	{
		int left = accumulate(v.begin(), v.begin() + i, 0);
		int right = accumulate(v.begin() + i, v.end(), 0);
		cout << "left" << left << ' ' << "right" << right << '\n';
		tmp = abs(left - right);
		//if (!vv.empty() and vv.at(vv.size() - 1) <= tmp) continue;
		vv.push_back(tmp);
		answer = min(answer, tmp);
	}
	auto it = find(vv.begin(), vv.end(), answer);
	answer = it - vv.begin();

	return answer;
}

int main()
{
	int n = 5;
	vector<int> v = {1,2,1,2,1};
	cout << solution(n, v);
}