#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
   int answer = 0;
	int divideNum = 1000000007;

	vector<vector<int>> maps(n, vector<int>(m, 0));

	for (auto puddle : puddles)
	{
		maps[puddle[1] - 1][puddle[0] - 1] = -1;
	}
	maps[0][0] = 1;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (maps[y][x] < 0) 
			{
				continue;
			}

			if (y == 0 && x != 0)
			{
				maps[y][x] = maps[y][x - 1];
			}
			else if (y != 0 && x == 0)
			{
				maps[y][x] = maps[y - 1][x];
			}
			else if (y != 0 && x != 0)
			{
				int left = maps[y][x - 1] > 0 ? maps[y][x - 1] : 0;
				int up = maps[y - 1][x] > 0 ? maps[y - 1][x] : 0;
				maps[y][x] = (left + up) % divideNum;
			}
		}
	}
	answer = maps[n - 1][m - 1];


	return answer;
}