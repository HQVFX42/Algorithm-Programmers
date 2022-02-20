#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	stack<int> box;
	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			int col = moves[i] - 1;
			if (board[j][col] != 0)
			{
				if (!box.empty() and box.top() == board[j][col])
				{
					box.pop();
					answer += 2;
				}
				else
				{
					box.push(board[j][col]);
				}
				board[j][col] = 0;
				break;
			}
		}
	}
	return answer;
}