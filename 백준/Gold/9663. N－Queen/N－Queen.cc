#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int pos[15] = { -1 };
int answer = 0;
int n = 0;

void queen(int x)
{
    if (x == n)
    {
        answer++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            pos[x] = i;

            bool canPut = true;
            for (int j = 0; j < x; j++)
            {
                if (pos[x] == pos[j] || abs(pos[x] - pos[j]) == x - j)
                {
                    canPut = false;
                    break;
                }
            }
            if (canPut)
                queen(x + 1);
        }
    }
}

int main()
{
    cin >> n;

    queen(0);

    cout << answer;

    return 0;
}