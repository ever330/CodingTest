#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

using namespace std;

char board[100][100];
bool visited[100][100] = { false, };
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void DFS(int x, int y, int n)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
			continue;

		if (!visited[nextY][nextX] && board[nextY][nextX] == board[y][x])
		{
			DFS(nextX, nextY, n);
		}
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}

	int sec1 = 0;
	int sec2 = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x])
			{
				DFS(x, y, n);
				sec1++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (board[y][x] == 'G')
			{
				board[y][x] = 'R';
			}
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x])
			{
				DFS(x, y, n);
				sec2++;
			}
		}
	}

	printf("%d %d", sec1, sec2);

	return 0;
}