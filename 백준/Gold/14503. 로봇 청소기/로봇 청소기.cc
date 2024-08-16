#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m = 0;
int r, c, d = 0;

int map[50][50];
int dc[4] = { 0, 1, 0, -1 };
int dr[4] = { -1, 0, 1, 0 };

int answer = 0;

void DFS()
{
    for (int i = 0; i < 4; i++)
    {
        int nextDir = (d + 3 - i) % 4;
        int nextRow = r + dr[nextDir];
        int nextCol = c + dc[nextDir];

        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || map[nextRow][nextCol] == 1)
        {
            continue;
        }

        if (map[nextRow][nextCol] == 0)
        {
            map[nextRow][nextCol] = 2;
            r = nextRow;
            c = nextCol;
            d = nextDir;
            answer++;
            DFS();
        }
    }

    int backDir = d > 1 ? d - 2 : d + 2;
    int backRow = r + dr[backDir];
    int backCol = c + dc[backDir];
    if (backRow >= 0 && backRow <= n || backCol >= 0 || backCol <= m)
    {
        if (map[backRow][backCol] == 0 || map[backRow][backCol] == 2)
        {
            r = backRow;
            c = backCol;
            DFS();
        }
        else
        {
            cout << answer << endl;
            exit(0);
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            int num = 0;
            cin >> num;
            map[y][x] = num;
        }
    }

    map[r][c] = 2;
    answer++;
    DFS();

    cout << answer;

    return 0;
}