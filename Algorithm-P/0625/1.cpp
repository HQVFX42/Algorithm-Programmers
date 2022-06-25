#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> cards, vector<string> shuffles)
{
	vector<int> answer;

	int ssz = shuffles.size();
	for (int i = 0; i < ssz; i++)
	{
		if (shuffles[i] == "Cut")
		{
			int csz = cards.size();
			int mid = csz * 0.5;
			int idx = 0;
			vector<int> tmp(csz);
			for (int j = 0; j < csz; j++)
			{
				tmp[idx++] = cards[j + mid];
			}
		}
	}

	return answer;
}
int main()
{
	
}