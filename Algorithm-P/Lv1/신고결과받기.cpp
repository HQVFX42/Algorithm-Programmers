#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> stoi;	// id to int 인덱스
    int n = id_list.size();
    set<int> s[1000];	// 유일 원소 집합을 사용하기 위한 set 컨테이너
    vector<int> count(n);
    for (int i = 0; i < n; i++)
    {
        stoi[id_list[i]] = i;
    }
    for (auto& rep : report)
    {
        stringstream st(rep);	// 공백처리
        string id1, id2;
        st >> id1 >> id2;
        s[stoi[id2]].insert(stoi[id1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i].size() < k) continue;
        for (auto x : s[i]) count[x]++;
    }
    return count;
}