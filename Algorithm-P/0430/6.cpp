#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];
string str;
int answer;

void funcRecursive(int k, int n, int m)
{
	if (k == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << ' ';
			str += arr[i] + '0';
		}
		if (stoi(str) % m == 0) answer++;
		cout << '\n';
		str = "";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (bUsed[i] == false)
		{
			arr[k] = i;
			bUsed[i] = true;
			funcRecursive(k + 1, n, m);
			bUsed[i] = false;
		}
	}
}

void dfs2(int depth, int n, int m)
{
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	do
	{
		reverse(v.begin() + n, v.end());
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << ' ';
			str += v[i] + '0';
		}
		if (stoi(str) % m == 0) answer++;
		cout << '\n';
		str = "";
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	funcRecursive(0, N, M);
	//dfs2(0, N, M);
	cout << answer;
	cout << str;
}