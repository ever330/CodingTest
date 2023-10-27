#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    map<int, int> foodCount;
    
    for (auto time : food_times)
    {
        if (foodCount.find(time) == foodCount.end())
            foodCount.insert({time, 1});
        else
            foodCount[time]++;
    }
    
    int prevMinTime = 0;
    int zeroCount = 0;
    while (k > 0)
    {
        auto iter = foodCount.upper_bound(prevMinTime);
        int tempMinTime = iter->first;
        long long eraseTime = (tempMinTime - prevMinTime) * (food_times.size() - zeroCount);
        if (eraseTime < k)
        {
            k -= eraseTime;
            prevMinTime = tempMinTime;
            zeroCount += foodCount[tempMinTime];
            
            if (zeroCount >= food_times.size())
            {
                answer = -1;
                break;
            }
        }
        else
        {
            int rest = k % (food_times.size() - zeroCount);
            zeroCount += foodCount[tempMinTime];
            if (eraseTime == k && zeroCount >= food_times.size())
            {
                answer = -1;
                break;
            }
            int count = 0;
            
            for (int i = 0; i < food_times.size(); i++)
            {
                if (food_times[i] >= tempMinTime)
                { 
                    if (count == rest)
                    {
                        answer = i + 1;
                        k = 0;
                        break;
                    }
                    count++;
                }
            }
        }
    }
    
    return answer;
}