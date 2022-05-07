#include <bits/stdc++.h>
using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    string answer(n,'X');

    set<int> s;
    stack<int> sDelete;
    for (int i = 0; i < n; i++) s.insert(i);
    auto it = s.find(k);
    for (auto& c : cmd)
    {
        if (c[0] == 'U')
        {
            int num = stoi(c.substr(2, 100));
            while (num--) it--;
        }
        else if (c[0] == 'D')
        {
            int num = stoi(c.substr(2, 100));
            while (num--) it++;
        }
        else if (c[0] == 'C')
        {
            sDelete.push(*it);
            it = s.erase(it);
            if (it == s.end()) it--;
        }
        else
        {
            s.insert(sDelete.top());
            sDelete.pop();
        }
    }
    for (auto& i : s)
    {
        answer[i] = 'O';
    }

    return answer;
}