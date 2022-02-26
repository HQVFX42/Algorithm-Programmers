#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> m;
	for (auto& i : participant) m[i]++;
	for (auto& i : completion) m[i]--;
	for (auto& i : m)
	{
		if (i.second != 0)
		{
			answer += i.first;
			break;
		}
	}
	return answer;
}

string solution2(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
			return participant[i];
	}
	return participant[participant.size() - 1];
	//return answer;
}