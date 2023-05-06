#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    vector<long long> arr(n);
    arr[0] = 1;
    arr[1] = 2;

    if (n > 2)
    {
        for (auto i = 2; i < n; i++)
        {
            arr[i] = arr[i - 2] % 1234567 + arr[i - 1] % 1234567;
        }
    }
    
    answer = arr[n - 1] % 1234567;
    
    return answer;
}