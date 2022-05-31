#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> appetites, int k)
{
	vector<int> answer;

	/*for (int i = 0; i < appetites.size(); i++)
	{
		int tmp = 0;
		for (int j = appetites[i] - k; j <= appetites[i] + k; j++)
		{
			auto num = count(appetites.begin(), appetites.end(), j);

			tmp += num;
		}
		answer.push_back(tmp-1);
	}*/

	int n = appetites.size();
	int lp = 0, rp = 0;
	int ans = 0;
	while (lp < n)
	{
		while (rp < n)
		{
			int diff = abs(appetites[rp] - appetites[lp]);
			if (diff <= k && lp != rp)
			{
				ans++;
			}
			rp++;
		}
		answer.push_back(ans);
		lp++;
		ans = 0;
		rp = 0;
	}
	//cout << ans;

	return answer;
}

int main()
{
	vector<int> appetites = { 1,10,5,4,5,2,8,3,15 };
	int k = 3;

	vector<int> v;
	v = solution(appetites, k);
	for (auto& i : v)
	{
		cout << i << ' ';
	}
}