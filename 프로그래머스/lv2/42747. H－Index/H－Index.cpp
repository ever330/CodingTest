#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) 
{
    int answer = 0;

    sort(citations.begin(), citations.end(), compare);
    int max = 0;

    for (auto i = 0; i < citations.size(); i++)
    {
        for (auto j = 0; j < 10001; j++)
        {
            if (j > i + 1)
                break;
            if (citations[i] >= j)
            {
                if (j > max)
                    max = j;
            }
            else
            {
                break;
            }
        }
    }
    answer = max;

    return answer;
}