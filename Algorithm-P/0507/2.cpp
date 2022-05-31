#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
	int answer = -2;

	int sum = 0;
	for (auto& i : queue1)
	{
		sum += i;
	}
	for (auto& i : queue2)
	{
		sum += i;
	}
	int n = sum * 0.5;
	
	return answer;
}