#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
    if (a[col - 1] != b[col - 1])
        return a[col - 1] < b[col - 1];
    else
        return a[0] > b[0];
    });
    
    for (int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;
        for (int j = 0; j < data[i - 1].size(); j++)
        {
            sum += data[i - 1][j] % i;
        }
        answer ^= sum;
    }
    
    return answer;
}