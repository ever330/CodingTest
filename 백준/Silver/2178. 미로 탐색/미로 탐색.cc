#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<char>> map;

    for (int y = 0; y < n; y++)
    {
        vector<char> mapX;
        for (int x = 0; x < m; x++)
        {
            char posX;
            cin >> posX;
            mapX.push_back(posX);
        }
        map.push_back(mapX);
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    visited[0][0] = true;
    dis[0][0] = 1;

    int dirX[4] = { 1, 0, -1, 0 };
    int dirY[4] = { 0, 1, 0, -1 };

    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        bool isEnd = false;

        for (int i = 0; i < 4; i++)
        {
            int nextX = tempX + dirX[i];
            int nextY = tempY + dirY[i];

            if (nextX == m - 1 && nextY == n - 1)
            {
                isEnd = true;
                dis[nextY][nextX] = dis[tempY][tempX] + 1;
                break;
            }

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;

            if (!visited[nextY][nextX] && map[nextY][nextX] == '1')
            {
                visited[nextY][nextX] = true;
                dis[nextY][nextX] = dis[tempY][tempX] + 1;
                q.push(make_pair(nextX, nextY));
            }
        }

        if (isEnd)
            break;
    }

    cout << dis[n - 1][m - 1];

    return 0;
}