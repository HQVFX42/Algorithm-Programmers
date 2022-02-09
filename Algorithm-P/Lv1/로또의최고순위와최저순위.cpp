#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rank[7] = { 6,6,5,4,3,2,1 };
    int correct = 0;
    int unknown = 0;

    for (auto& i : lottos)
    {
        if (i == 0) unknown++;
    }

    for (auto& idx : win_nums)
    {
        auto it = find(lottos.begin(), lottos.end(), idx);
        if (it != lottos.end()) correct++;
    }

    int tpRank = rank[unknown + correct];
    int btRank = rank[correct];

    answer.push_back(tpRank);
    answer.push_back(btRank);

    return answer;
}