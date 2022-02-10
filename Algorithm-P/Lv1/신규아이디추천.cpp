//#include <bits/stdc++.h>
//using namespace std;
//
//string solution(string new_id) {
//	// step1
//	for (int i = 0; i < new_id.length(); i++)
//	{
//		if ('A' <= new_id[i] and new_id[i] <= 'Z')
//		{
//			new_id[i] = tolower(new_id[i]);
//		}
//	}
//	// step2
//	for (int i = 0; i < new_id.length();)
//	{
//		if (('a' <= new_id[i] and new_id[i] <= 'z') or
//			('0' <= new_id[i] and new_id[i] <= '9') or
//			new_id[i] == '-' or new_id[i] == '_' or new_id[i] == '.')
//		{
//			i++;
//			continue;
//		}
//		new_id.erase(new_id.begin() + i);
//	}
//	// step3
//	for (int i = 1; i < new_id.length();)
//	{
//		if (new_id[i] == '.' and new_id[i - 1] == '.')
//		{
//			new_id.erase(new_id.begin() + i);
//			continue;
//		}
//		i++;
//	}
//	// step4
//	if (new_id.front() == '.')
//	{
//		new_id.erase(new_id.begin());
//	}
//	if (new_id.back() == '.')
//	{
//		new_id.erase(new_id.end() - 1);
//	}
//	// step5
//	if (new_id.empty())
//	{
//		new_id = 'a';
//	}
//	// step6
//	if (new_id.length() >= 16)
//	{
//		while (new_id.length() != 15)
//		{
//			new_id.erase(new_id.begin() + 15);
//		}
//		if (new_id.back() == '.')
//		{
//			new_id.erase(new_id.end() - 1);
//		}
//	}
//	// step7
//	if (new_id.length() <= 2)
//	{
//		while (new_id.length() != 3)
//		{
//			new_id += new_id.back();
//		}
//	}
//	return new_id;
//}

#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string tmp;
    for (char& c : new_id) if (isupper(c)) c = tolower(c);
    for (char c : new_id) if (islower(c) or isdigit(c) or strchr("-_.", c)) tmp += c;
    new_id.clear();
    for (int i = 0; i < tmp.size(); i++)
        if (tmp[i] != '.' or (!new_id.empty() && new_id.back() != '.')) new_id += tmp[i];
    if (new_id.empty()) new_id.push_back('a');
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    while (new_id.back() == '.') new_id.pop_back();
    while (new_id.size() <= 2) new_id += new_id.back();
    return new_id;
}