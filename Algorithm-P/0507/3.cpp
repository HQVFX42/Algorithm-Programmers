#include <bits/stdc++.h>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
	int answer = 0;

	int vs = problems.size();

	int tmp1 = problems[0][0] - alp;
	int tmp2 = problems[0][1] - cop;
	alp = problems[0][0];
	cop = problems[0][1];
	answer += tmp1 + tmp2;
	for (int i = 0; i < vs;)
	{
		while (true)
		{
			if (i != vs-1 and alp >= problems[i + 1][0] and cop >= problems[i + 1][1])
			{
				i++;
			}
			alp += problems[i][2];
			cop += problems[i][3];
			answer += problems[i][4];
		}
	}

	return answer;
}

int main()
{
	int alp = 0;
	int cop = 0;
	vector<vector<int>> p = { {0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2} };
	int n = solution(alp, cop, p);
	cout << n;
}