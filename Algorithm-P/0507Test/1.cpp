#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
	string answer = "";

	map<char, int> m; // misc, score
	m.insert({ 'R', 0 });
	m.insert({ 'T', 0 });
	m.insert({ 'C', 0 });
	m.insert({ 'F', 0 });
	m.insert({ 'J', 0 });
	m.insert({ 'M', 0 });
	m.insert({ 'A', 0 });
	m.insert({ 'N', 0 });

	for (int i = 0; i < survey.size(); i++)
	{
		if (choices[i] == 1)
		{
			m[survey[i][0]] += 3;
		}
		else if (choices[i] == 2)
		{
			m[survey[i][0]] += 2;
		}
		else if (choices[i] == 3)
		{
			m[survey[i][0]] += 1;
		}
		else if (choices[i] == 4)
		{
			m[survey[i][0]] += 0;
			m[survey[i][1]] += 0;
		}
		else if (choices[i] == 5)
		{
			m[survey[i][1]] += 1;
		}
		else if (choices[i] == 6)
		{
			m[survey[i][1]] += 2;
		}
		else if (choices[i] == 7)
		{
			m[survey[i][1]] += 3;
		}
	}

	if (m.at('R') < m.at('T'))
	{
		answer += 'T';
	}
	else if (m.at('R') >= m.at('T'))
	{
		answer += 'R';
	}

	if (m.at('C') < m.at('F'))
	{
		answer += 'F';
	}
	else if (m.at('C') >= m.at('F'))
	{
		answer += 'C';
	}

	if (m.at('J') < m.at('M'))
	{
		answer += 'M';
	}
	else if (m.at('J') >= m.at('M'))
	{
		answer += 'J';
	}
	if (m.at('A') < m.at('N'))
	{
		answer += 'N';
	}
	else if (m.at('A') >= m.at('N'))
	{
		answer += 'A';
	}

	return answer;
}

int main()
{
	vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
	vector<int> choices = { 5,3,2,7,5 };
	cout << solution(survey, choices);
}