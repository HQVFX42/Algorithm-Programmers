#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	map<string, int> m;
	for (int i = 0; i < phone_book.size(); i++) m[phone_book[i]] = 1;
	for (int i = 0; i < phone_book.size(); i++)
	{
		string tmp = "";
		for (int j = 0; j < phone_book[i].length() - 1; j++)
		{
			tmp += phone_book[i][j];
			if (m[tmp]) answer = false;
		}
	}

	return answer;
}