#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int box[100][100][100];

struct Pos
{
    int x;
    int y;
    int z;

    Pos(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
};

int main()
{
    int answer = 0;
    int m, n, h = 0;

    cin >> m >> n >> h;

    queue<Pos> q;
    int count = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int num;
                cin >> num;
                box[i][j][k] = num;

                if (num == 1)
                {
                    q.push(Pos(k, j, i));
                }
            }
        }
    }

    count = q.size();
    int nextCount = 0;

    while (!q.empty())
    {
        Pos pos = q.front();
        q.pop();
        count--;

        if (pos.x > 0 && box[pos.z][pos.y][pos.x - 1] == 0)
        {
            box[pos.z][pos.y][pos.x - 1] = 1;
            nextCount++;
            q.push(Pos(pos.x - 1, pos.y, pos.z));
        }
        if (pos.x < m - 1 && box[pos.z][pos.y][pos.x + 1] == 0)
        {
            box[pos.z][pos.y][pos.x + 1] = 1;
            nextCount++;
            q.push(Pos(pos.x + 1, pos.y, pos.z));
        }
        if (pos.y > 0 && box[pos.z][pos.y - 1][pos.x] == 0)
        {
            box[pos.z][pos.y - 1][pos.x] = 1;
            nextCount++;
            q.push(Pos(pos.x, pos.y - 1, pos.z));
        }
        if (pos.y < n - 1 && box[pos.z][pos.y + 1][pos.x] == 0)
        {
            box[pos.z][pos.y + 1][pos.x] = 1;
            nextCount++;
            q.push(Pos(pos.x, pos.y + 1, pos.z));
        }
        if (pos.z > 0 && box[pos.z - 1][pos.y][pos.x] == 0)
        {
            box[pos.z - 1][pos.y][pos.x] = 1;
            nextCount++;
            q.push(Pos(pos.x, pos.y, pos.z - 1));
        }
        if (pos.z < h - 1 && box[pos.z + 1][pos.y][pos.x] == 0)
        {
            box[pos.z + 1][pos.y][pos.x] = 1;
            nextCount++;
            q.push(Pos(pos.x, pos.y, pos.z + 1));
        }

        if (count == 0 && !q.empty())
        {
            count = nextCount;
            nextCount = 0;
            answer++;
        }
    }

    bool allChanged = true;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (box[i][j][k] == 0)
                {
                    allChanged = false;
                    answer = -1;
                    break;
                }
            }
            if (!allChanged)
                break;
        }
        if (!allChanged)
            break;
    }

    cout << answer;

    return 0;
}