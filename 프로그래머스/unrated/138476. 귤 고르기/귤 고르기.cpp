#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> count(10000001);

    for (auto i = 0; i < tangerine.size(); i++)
    {
        count[tangerine[i]]++;
    }

    sort(count.begin(), count.end(), compare);

    for (auto i = 0; i < count.size(); i++)
    {
        k -= count[i];
        answer++;
        if (k <= 0)
        {
            break;
        }
    }
    
    return answer;
}