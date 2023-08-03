#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long workTime = 0;

    for (auto work : works)
    {
        workTime += work;
    }

    if (n >= workTime)
    {
        return answer;
    }

    sort(works.begin(), works.end(), greater<int>());

    int index = 0;
    while (n > 0)
    {
        if (index == works.size() - 1)
        {
			break;
        }
		if (works[index] > works[index + 1])
		{
            works[index]--;
            index--;
            n--;
		}
        else
        {
	        index++;
        }
    }
    
    for (auto work : works)
    {
		if (n > 0)
		{
            work--;
            n--;
		}
        answer += pow(work, 2);
    }

    return answer;
}
