#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row = board.size();
    int column = board[0].size();
    
    int dp[1000][1000];
    
    for (int i = 0; i < row; i++)
    {
        dp[i][0] = board[i][0];
    }
    for (int i = 0; i < column; i++)
    {
        dp[0][i] = board[0][i];
    }
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            if (board[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            
            int dp1 = dp[i - 1][j - 1];
            int dp2 = dp[i - 1][j];
            int dp3 = dp[i][j - 1];
            
            if (dp1 == dp2 && dp2 == dp3)
            {
                dp[i][j] = dp1 + 1;
            }
            else
            {
                dp[i][j] = min(dp1, min(dp2, dp3)) + 1;
            }
        }
    }
    
    int m = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            m = max(m, dp[i][j]);
        }
    }
    
    answer = m * m;
    
    return answer;
}