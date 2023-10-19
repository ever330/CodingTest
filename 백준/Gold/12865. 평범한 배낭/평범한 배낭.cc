#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    vector<pair<int, int>> objects;
    objects.push_back(make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        int weight, worth;
        scanf("%d %d", &weight, &worth);

        objects.push_back(make_pair(weight, worth));
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            if (j - objects[i].first >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], objects[i].second + dp[i - 1][j - objects[i].first]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxWorth = 0;
    for (int i = 0; i < k + 1; i++)
    {
        if (maxWorth < dp[n][k])
        {
            maxWorth = dp[n][k];
        }
    }

    printf("%d", maxWorth);

    return 0;
}