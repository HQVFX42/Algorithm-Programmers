#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> m;
	for (auto& type : clothes) m[type[1]]++;
	for (auto iter = m.begin(); iter != m.end(); iter++) answer *= iter->second + 1;

	return answer - 1;
}