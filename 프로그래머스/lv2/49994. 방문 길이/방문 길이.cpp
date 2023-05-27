#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
	vector<int> nowPos;
	nowPos.emplace_back(0);
	nowPos.emplace_back(0);

	vector<vector<string>> xMoveDir(11);
	vector<vector<string>> yMoveDir(11);

	for (auto i = 0; i < dirs.size(); i++)
	{
		if (dirs[i] == 'L')
		{
			if (nowPos[0] > -5)
			{
				string dir = to_string(nowPos[0] - 1);
				dir += to_string(nowPos[0]);
				nowPos[0] -= 1;
				if (find(xMoveDir[nowPos[1] + 5].begin(), xMoveDir[nowPos[1] + 5].end(), dir) == xMoveDir[nowPos[1] + 5].end())
				{
					answer++;
					xMoveDir[nowPos[1] + 5].emplace_back(dir);
				}
			}
		}
		else if (dirs[i] == 'R')
		{
			if (nowPos[0] < 5)
			{
				string dir = to_string(nowPos[0]);
				dir += to_string(nowPos[0] + 1);
				nowPos[0] += 1;
				if (find(xMoveDir[nowPos[1] + 5].begin(), xMoveDir[nowPos[1] + 5].end(), dir) == xMoveDir[nowPos[1] + 5].end())
				{
					answer++;
					xMoveDir[nowPos[1] + 5].emplace_back(dir);
				}
			}
		}
		else if (dirs[i] == 'U')
		{
			if (nowPos[1] < 5)
			{
				string dir = to_string(nowPos[1]);
				dir += to_string(nowPos[1] + 1);
				nowPos[1] += 1;
				if (find(yMoveDir[nowPos[0] + 5].begin(), yMoveDir[nowPos[0] + 5].end(), dir) == yMoveDir[nowPos[0] + 5].end())
				{
					answer++;
					yMoveDir[nowPos[0] + 5].emplace_back(dir);
				}
			}
		}
		else if (dirs[i] == 'D')
		{
			if (nowPos[1] > -5)
			{
				string dir = to_string(nowPos[1] - 1);
				dir += to_string(nowPos[1]);
				nowPos[1] -= 1;
				if (find(yMoveDir[nowPos[0] + 5].begin(), yMoveDir[nowPos[0] + 5].end(), dir) == yMoveDir[nowPos[0] + 5].end())
				{
					answer++;
					yMoveDir[nowPos[0] + 5].emplace_back(dir);
				}
			}
		}
	}

    return answer;
}