#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, r, c = 0;
int answer = 0;

void FindZ(int x, int y, int size)
{
    if (x == c && y == r)
    {
        cout << answer;
    }
    else if (c >= x && r >= y && c < x + size && r < y + size)
    {
        FindZ(x, y, size / 2);
        FindZ(x + size / 2, y, size / 2);
        FindZ(x, y + size / 2, size / 2);
        FindZ(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        answer += size * size;
    }
}

int main()
{

    cin >> n >> r >> c;

    FindZ(0, 0, pow(2, n));

    return 0;
}