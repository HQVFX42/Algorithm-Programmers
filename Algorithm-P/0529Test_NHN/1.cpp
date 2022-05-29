#include <bits/stdc++.h>
using namespace std;

int cnt[111][55], pre1[111][55], pre2[111][55];

int solution(vector<vector<int>> cards1, vector<vector<int>> cards2)
{
	int answer = 0;

	int sz = cards1.size();
	for (int i = 1; i <= sz; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cnt[i][cards1[i - 1][j]]++;
			cnt[i][cards2[i - 1][j]]++;

			pre1[i][cards1[i - 1][j]] = pre1[i - 1][cards1[i - 1][j]] + cnt[i][cards1[i - 1][j]];
			pre2[i][cards2[i - 1][j]] = pre2[i - 1][cards2[i - 1][j]] + cnt[i][cards2[i - 1][j]];
		}
	}
	for (int i = 1; i <= sz; i++)
	{
		int tmp1 = 0, tmp2 = 0;
		for (int j = 1; j <= 52; j++)
		{
			if (cnt[i][j] >= 2)
			{
				answer++;
				break;
			}

			if (pre1[i][j] >= 2)
			{
				tmp1++;
				if (tmp1 >= 2)
				{
					answer++;
					break;
				}
			}
			if (pre2[i][j] >= 2)
			{
				tmp2++;
				if (tmp2 >= 2)
				{
					answer++;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= sz; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			cout << pre2[i][j] << ' ';
		}
		cout << '\n';
	}

	return answer;
}

int main()
{
	vector<vector<int>> v = { {13,21,24,29,50},{1,12,20,21,32} };
	vector<vector<int>> v2 = { {5,10,15,41,49},{6,14,15,19,46} };
	cout << solution(v, v2);
}