#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int score[3] = {};
    int a[5] = { 1,2,3,4,5 };
    int b[8] = { 2,1,2,3,2,4,2,5 };
    int c[10] = { 3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (a[i % 5] == answers[i]) score[0]++;
        if (b[i % 8] == answers[i]) score[1]++;
        if (c[i % 10] == answers[i]) score[2]++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (score[i] == *max_element(score, score+3))
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}