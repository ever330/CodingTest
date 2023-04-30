#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int half;

    if (n % 2 == 0)
    {
        half = n / 2;
    }
    else
    {
        half = n / 2 + 1;
    }

    for (auto i = 1; i <= half; i++)
    {
        int sum = 0;
        sum += i;
        for (auto j = i + 1; j <= half + 1; j++)
        {
            sum += j;
            if (sum == n)
            {
                answer++;
                break;
            }
            else if (sum > n)
            {
                break;
            }
        }
    }
    answer++;

    return answer;
}