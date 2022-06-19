#include <bits/stdc++.h>
using namespace std;

long long solution(vector<string> p)
{
	long long answer = 0;

	stack<long long> s;
	int psz = p.size();
	for (int i = 0; i < psz; i++)
	{
		if (p[i] == "+")
		{
			long long n1 = s.top();
			s.pop();
			long long n2 = s.top();
			s.pop();
			s.push(n2 + n1);
		}
		else if (p[i] == "-")
		{
			long long n1 = s.top();
			s.pop();
			long long n2 = s.top();
			s.pop();
			s.push(n2 - n1);
		}
		else if (p[i] == "/")
		{
			long long n1 = s.top();
			s.pop();
			long long n2 = s.top();
			s.pop();
			s.push(n2 / n1);
		}
		else if (p[i] == "*")
		{
			long long n1 = s.top();
			s.pop();
			long long n2 = s.top();
			s.pop();
			s.push(n2 * n1);
		}
		else
		{
			long long tmp = stoll(p[i]);
			s.push(tmp);
		}
	}

	answer = s.top();

	return answer;
}
int main()
{
	vector<string> v1 = { "12","2","5", "+","*","9","3","/","-" };
	vector<string> v2 = { "99999","99999","99999","99999","99999","99999","99999","99999","99999","*","*" ,"*" ,"*" ,"*" ,"*" ,"*" ,"*" ,"*" };
	cout << solution(v2);
}