#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

	vector<string> tmp;
	for (int i = 0; i < numbers.size(); i++)
	{
		tmp.push_back(to_string(numbers[i]));
	}
	sort(tmp.begin(), tmp.end(),
		[&](string lhs, string rhs) 
		{
			return lhs + rhs > rhs + lhs; 
		});
	for (int i = 0; i < tmp.size(); i++)
	{
		answer += tmp[i];
	}
	if (answer[0] == '0') answer = '0';

    return answer;
}