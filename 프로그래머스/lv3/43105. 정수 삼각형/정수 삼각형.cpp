#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<int> prevSum(triangle.size());
    vector<int> nowSum(triangle.size());

    prevSum[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                nowSum[j] = prevSum[j] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                nowSum[j] = prevSum[j - 1] + triangle[i][j];
            }
            else
            {
                int left = prevSum[j - 1] + triangle[i][j];
                int right = prevSum[j] + triangle[i][j];
                nowSum[j] = left < right ? right : left;
            }
        }
        prevSum = nowSum;
    }

    answer = *max_element(nowSum.begin(), nowSum.end());

    return answer;
}