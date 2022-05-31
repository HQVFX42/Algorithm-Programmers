#include <bits/stdc++.h>
using namespace std;

int ans;
string tmp[333];
set<string, greater<string>> S;

void dfs(int k, string s)
{
	vector<bool> bUsed;
	for (int i = 0; i < s.size(); i++)
	{
		bUsed.push_back(i < k ? 0 : 1);
	}

	do
	{
		string ts = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (bUsed[i] == 0)
			{
				//cout << s[i] << ' ';
				//tmp[ans] += s[i];
				ts += s[i];
			}
		}
		S.insert(ts);
		//ans++;
		//cout << ans << '\n';
	} while (next_permutation(bUsed.begin(), bUsed.end()));
}

string solution(string s)
{
	string answer = "";

	for (int i = 1; i <= s.size(); i++)
	{
		dfs(i, s);
	}

	//sort(tmp, tmp + ans, [&](string lhs, string rhs) {return lhs > rhs; });

	//answer = tmp[ans-1];
	//answer = tmp[0];
	//answer = S.size();
	for (auto& i : S)
	{
		//cout << "S:" << i;
	}
	answer = *S.begin();
	return answer;
}

int main()
{
	string s = "baba";
	cout << solution(s);
}