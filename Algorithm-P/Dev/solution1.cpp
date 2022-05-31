#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> purchase)
{
	vector<int> answer;

	vector<int> tmpCost;
	vector<int> tmpDay;
	for (auto& i : purchase)
	{
		stringstream str(i);
		string info, cost;
		str >> info >> cost;
		tmpCost.push_back(stoi(cost));
	}
	for (auto& i : purchase)
	{
		stringstream str(i);
		string stringBuffer;
		while (getline(str, stringBuffer, '/'))
		{
			tmpDay.push_back(stoi(stringBuffer));
		}
	}
	
	return answer;
}

int main()
{
	vector<string> v = { "2019/01/01 5000", "2019/02/02 15000" };
	solution(v);
}