#include <bits/stdc++.h>
using namespace std;

int vis[222];

void func(vector<vector<int>>& v, int depth)
{
    vis[depth] = 1;
    for (int i = 0; i < v[depth].size(); i++)
    {
        if (!vis[i] and v[depth][i] == 1)
        {
            func(v, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            func(computers, i);
            answer++;
        }
    }

    return answer;
}