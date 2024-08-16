#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, k = 0;

int answer = 0;

int main()
{
    cin >> n >> k;

    int coin[101] = { 0 };
    int dp[10001] = { 0 };
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }

    answer = dp[k];

    cout << answer;

    return 0;
}