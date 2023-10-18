#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> map;

    for (int y = 0; y < m; y++)
    {
        vector<int> mapX;
        for (int x = 0; x < n; x++)
        {
            int posX;
            cin >> posX;
            mapX.push_back(posX);
        }
        map.push_back(mapX);
    }

    bool hasZero = false;

    queue<pair<int, int>> q;
    vector<vector<int>> dis(m, vector<int>(n, 0));

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == 0)
                hasZero = true;

            if (map[y][x] == 1)
            {
                q.push(make_pair(x, y));
                dis[y][x] = 0;
            }
        }
    }

    if (!hasZero)
    {
        cout << 0;

        return 0;
    }

    int dirX[4] = { 1, 0, -1, 0 };
    int dirY[4] = { 0, 1, 0, -1 };


    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        bool hasChanged = false;

        for (int i = 0; i < 4; i++)
        {
            int nextX = tempX + dirX[i];
            int nextY = tempY + dirY[i];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && map[nextY][nextX] == 0)
            {
                map[nextY][nextX] = 1;
                dis[nextY][nextX] = dis[tempY][tempX] + 1;
                q.push(make_pair(nextX, nextY));
                hasChanged = true;
            }
        }
    }

    int maxDis = 0;

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (dis[y][x] > maxDis)
                maxDis = dis[y][x];

            if (map[y][x] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << maxDis;

    return 0;
}