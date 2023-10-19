#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int Min = 1000000000;
int N, M;
vector<pair<int, int>> ChicPos;
vector<pair<int, int>> HousPos;
bool Visited[13];
vector<pair<int, int>> SelectedPos;

void Distance()
{
	int res = 0;

	for (int i = 0; i < HousPos.size(); i++)
	{
		int minDis = 1000000000;
		for (int j = 0; j < SelectedPos.size(); j++)
		{
			minDis = min(minDis, abs(HousPos[i].first - SelectedPos[j].first) + abs(HousPos[i].second - SelectedPos[j].second));
		}
		res += minDis;
	}

	Min = min(res, Min);
}

void FindCom(int index, int m)
{
	if (m == M)
	{
		Distance();
	}

	for (int i = index; i < ChicPos.size(); i++)
	{
		if (Visited[i])
			continue;

		Visited[i] = true;
		SelectedPos.push_back(make_pair(ChicPos[i].first, ChicPos[i].second));
		FindCom(i, m + 1);
		Visited[i] = false;
		SelectedPos.pop_back();
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	int board[50][50];

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int num;
			scanf("%d", &num);
			board[y][x] = num;
			if (num == 1)
			{
				HousPos.push_back(make_pair(x, y));
			}
			else if (num == 2)
			{
				ChicPos.push_back(make_pair(x, y));
			}
		}
	}

	FindCom(0, 0);

	printf("%d", Min);

	return 0;
}