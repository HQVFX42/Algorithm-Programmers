#include <bits/stdc++.h>
using namespace std;

int solution(int money, string expected, string actual)
{
	int answer = -1;

	int n = money;
	bool stat = false;
	bool first = false;
	int tmp = 100;
	for (int i = 0; i < expected.size(); i++)
	{
		if (first == false)
		{
			n -= 100;
			first = true;
		}
		if (expected[i] != actual[i])
		{
			stat = false;
		}
		else
		{
			stat = true;
		}
		if (stat == true)
		{
			n += tmp;
			tmp = 100;
			first = false;
		}
		if (stat == false)
		{
			tmp = tmp * 2;
		}
	}
	answer = n;
	return answer;
}

int main()
{
	int m = 1000;
	string s = "HTHTHTH";
	string ss = "TTHHTTH";
	int ans = solution(m, s, ss);
	cout << ans;
}