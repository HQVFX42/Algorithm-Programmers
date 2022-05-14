#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> birth)
{
	int answer = 0;

	for (int i = 0; i < birth.size(); i++)
	{
		int year = 0, month = 0, day = 0;
		bool hasNum = false;
		for (char c : birth[i]) if (isdigit(c)) hasNum = true;
		bool b1 = false, b2 = false, b3 = false, b4 = false;
		

		if (birth[i].size() == 10 and hasNum)
		{
			year = stoi(birth[i].substr(0, 4));
			month = stoi(birth[i].substr(5, 6));
			day = stoi(birth[i].substr(8, 9));
			b1 = true;
		}
		if (1900 <= year and year <= 2021) b2 = true;
		if (01 <= month and month <= 12) b3 = true;
		if (month == 1 or month ==3 or month == 5 or month ==7 or month ==8 or month ==10 or month == 12)
		{
			if (1 <= day and day <= 31) b4 = true;
		}
		if(month == 4 or month == 6 or month == 9 or month == 11)
		{
			if (1 <= day and day <= 30) b4 = true;
		}
		if (month == 2)
		{
			if (year % 400 == 0 or year % 4 == 0 and year % 100 != 0)
			{
				if (1 <= day and day <= 29) b4 = true;
			}
			else
			{
				if (1 <= day and day <= 28) b4 = true;
			}
		}

		if (b1 == true and b2 == true and b3 == true and b4 == true) answer++;
	}

	return answer;
}

int main()
{
	vector<string> birth = { {"1996-02-29"}};
	int n = solution(birth);
	cout << n;
}