#include <vector>
#include <algorithm>

using namespace std;

long long arr[90001];
long long blockSum[90001];

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = -1;
    
    int n = land.size();
    
    int index = 1;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            arr[index] = land[y][x];
            index++;
        }
    }
    
    n *= n;
    sort(arr, arr + n + 1);
    
    for (int i = 1; i <= n; i++)
        blockSum[i] = blockSum[i - 1] + arr[i];
    
    int tempNum = -1;
    
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == tempNum)
            continue;
        
        tempNum = arr[i];
        
        long long money = 0;
        money += (blockSum[n] - blockSum[i - 1] - arr[i] * (n - (i - 1))) * Q;
        money += (arr[i] * (i - 1) - blockSum[i - 1]) * P;
        if (answer == -1 || answer > money)
            answer = money;
    }
    
    return answer;
}