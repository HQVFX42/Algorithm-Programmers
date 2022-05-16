#include <bits/stdc++.h>
using namespace std;

const int MAX = 3333;
int t[MAX];

int solution(int n, int maxhp, vector<int> times, vector<int> effects) 
{
    int answer = 0;
	int add = 0;
	int curhp = 0;
	while (true)
	{
		int time = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				add += effects[j];
				curhp += add;
			}
		}
		time++;
	}

    return answer;
}