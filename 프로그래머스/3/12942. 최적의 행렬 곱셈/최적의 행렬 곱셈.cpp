#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int n = matrix_sizes.size();
    
    vector<vector<int>> dp(n, vector<int>(n, 1000000000));
    
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    
    for (int range = 0; range < n; range++)
    {
        for (int i = 0; i < n - range; i++)
        {
            int j = i + range;
            if (j == i)
                continue;
            
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
            }
        }
    }
    
    answer = dp[0][n - 1];
    
    return answer;
}