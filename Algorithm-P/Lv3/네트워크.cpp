#include <bits/stdc++.h>
using namespace std;

int vis[222];

void dfs(vector<vector<int>>& v, int depth)
{
    vis[depth] = 1;
    for (int i = 0; i < v[depth].size(); i++)
    {   // depth��°�� ����� ��ǻ�͵� Ž��
        if (!vis[i] and v[depth][i] == 1)
        {   // ���� �湮���� �ʾ����鼭, �ٸ� ��ǻ�Ϳ� ����� �ִٸ�
            dfs(v, i);
        }
    }
}

void bfs(vector<vector<int>>& v, int st)
{
    vis[st] = 1;
    queue<int> q;
    q.push(st);

    while (!q.empty())
    {
        int x = q.front(); q.pop();
        for (int i = 0; i < v.size(); i++)
        {
            if (vis[i] == 1 or v[x][i] == 0) continue;
            else
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
    {   // ���� �˻����� ���� ��ǻ���϶�
        if (!vis[i])
        {
            //dfs(computers, i);
            bfs(computers, i);
            answer++;   // ��Ͱ� ������ ����� �׷��� �ϳ�
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> v = { {1,1,0},{1,1,0}, {0,0,1} };
    int ans = solution(n, v);
    cout << ans;    // 2
}