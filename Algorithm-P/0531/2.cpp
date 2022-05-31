#include <bits/stdc++.h>
using namespace std;

string d[66];

string mySwap(string& s)
{
	int sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		if (s[i] == '0')
		{
			s[i] = '1';
		}
		else
		{
			s[i] = '0';
		}
	}
	return s;
}

string solution(int n, long long x, long long y)
{
	string answer = "";

	d[1] = "0";
	d[2] = "01";
	//d[3] = "0110";
	//d[4] = "01101001";

	for (int i = 3; i <= 14; i++)
	{
		string tmp = "";
		tmp = d[i - 1];
		mySwap(tmp);
		d[i] = d[i - 1] + tmp;
	}
	int st = x - 1, en = y - x + 1;
	if (n> 14 and x >= 10000 or y >= 10000)
	{
		while (st < 10000)
		{
			st = x % 4;
		}

	}
	answer = d[14].substr(st, en);

	return answer;
}


int main()
{
	int n = 50;
	long long x = 10000;
	long long y = 10005;
	cout << solution(n, x, y);
}