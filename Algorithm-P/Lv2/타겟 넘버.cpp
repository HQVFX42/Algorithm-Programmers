#include <bits/stdc++.h>
using namespace std;

void func(vector<int>& numbers, int target, int& answer, int sum = 0, int depth = 0)
{
	if (depth == numbers.size())
	{
		if (sum == target)
		{
			answer++;
		}
		return;
	}
	func(numbers, target, answer, sum + numbers[depth], depth + 1);
	func(numbers, target, answer, sum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	func(numbers, target, answer);
	return answer;
}