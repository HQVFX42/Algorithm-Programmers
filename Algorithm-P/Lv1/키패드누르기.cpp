#include <bits/stdc++.h>
using namespace std;

string answer = "";
int L = 10, R = 12, distL = 0, distR = 0;

void funcL(int n)
{
	answer += 'L';
	L = n;
}
void funcR(int n)
{
	answer += 'R';
	R = n;
}

string solution(vector<int> numbers, string hand) {

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7)
		{
			funcL(numbers[i]);
		}
		else if (numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9)
		{
			funcR(numbers[i]);
		}
		else
		{
			if (numbers[i] == 0) numbers[i] = 11;
			int tmpL = abs(L - numbers[i]), tmpR = abs(R - numbers[i]);

			distL = (tmpL / 3) + (tmpL % 3); distR = (tmpR / 3) + (tmpR % 3);

			if (distL == distR)
			{
				if (hand == "left")
				{
					funcL(numbers[i]);
				}
				else
				{
					funcR(numbers[i]);
				}
			}
			else if (distL < distR)
			{
				funcL(numbers[i]);
			}
			else 
			{
				funcR(numbers[i]);
			}
		}
	}
	return answer;
}