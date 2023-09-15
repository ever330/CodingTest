#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    long long sum1 = 0;
    long long sum2 = 0;
    int maxNum = 0;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
        if (maxNum < queue1[i])
            maxNum = queue1[i];
        
        if (maxNum < queue2[i])
            maxNum = queue2[i];
    }
    
    long long avg = (sum1 + sum2) / 2;
    
    if ((sum1 + sum2) % 2 != 0 || maxNum > avg)
        return -1;
        
    int q1Index = 0;
    int q2Index = 0;
    int maxSize = queue1.size() + queue2.size();
    answer = 0;
    while (sum1 != sum2)
    {
        if (sum1 > sum2)
        {
            sum1 -= queue1[q1Index];
            sum2 += queue1[q1Index];
            queue2.push_back(queue1[q1Index]);
            q1Index++;
            //queue1.erase(queue1.begin());
            answer++;
        }
        else if (sum1 < sum2)
        {
            sum2 -= queue2[q2Index];
            sum1 += queue2[q2Index];
            queue1.push_back(queue2[q2Index]);
            q2Index++;
            //queue2.erase(queue2.begin());
            answer++;
        }
        
        if (answer > maxSize * 3)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}