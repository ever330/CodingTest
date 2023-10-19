#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

void MakeSpace(vector<vector<char>>& board, int posX, int posY, int n)
{
    int k = n / 3;
    for (int y = posY; y < posY + n; y++)
    {
        for (int x = posX; x < posX + n; x++)
        {
            if ((x - posX) / k == 1 && (y - posY) / k == 1)
            {
                board[y][x] = ' ';
            }
        }
    }

    if (k > 1)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                MakeSpace(board, x * k + posX, y * k + posY, k);
            }
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    vector<vector<char>> board(n, vector<char>(n, '*'));

    MakeSpace(board, 0, 0, n);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }

    return 0;
}