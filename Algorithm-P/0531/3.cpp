#include <bits/stdc++.h>
using namespace std;

void update(int idx)
{

}

int solution(int K, vector<string> user_scores)
{
	int answer = 0;

	map<string, string> m;
	vector<int> rank;
	int sz = user_scores.size();
	vector<int> v(K);
	for (int i = 0; i < sz; i++)
	{
		string tmp;
		tmp = user_scores[i];
		string name, score;
		name = tmp.substr(0, tmp.find(' '));
		score = tmp.substr(tmp.find(' ') + 1, tmp.length());
		//cout << name << ' ' << score << '\n';
		m[score] = name;
		rank.push_back(stoi(score));
		sort(rank.begin(), rank.end(), [&](int lhs, int rhs) {return lhs > rhs; });
		for (int j = 0; j < K; j++)
		{
			vector<int> tmp;
			if (j < rank.size())
			{
				v[j] = rank[j];
			}
		}
	}

	for (auto& i : v)
	{
		cout << i << ' ';
	}

	for (auto& i : rank)
	{
		//cout << i.first << ' ' << i.second << '\n';
	}


	return answer;
}

int main()
{
	int k = 3;
	vector<string> v = { "alex111 100","cheries2 200","coco 150","luna 100","alex111 120","coco 300","cheries2 110" };
	int ans = solution(k, v);
	//cout << ans;
}