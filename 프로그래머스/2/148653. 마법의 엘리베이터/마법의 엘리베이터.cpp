#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int count = 0;
    int num = storey;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    
    for (int i = 1; i <= count; i++)
    {
        int curPow = pow(10, i - 1);
        int curNum = (storey / curPow) % 10;
        if (curNum == 5 && i < count)
        {
            int nextPow = pow(10, i);
            int nextNum = (storey / nextPow) % 10;
            if (nextNum >= 5)
            {
                answer += curNum;
                storey += curNum * curPow;
            }
            else
            {
                answer += curNum;
                storey -= curNum * curPow;
            }
        }
        else if (curNum == 5 && i == count)
        {
            answer += curNum;
            storey -= curNum * curPow;
        }
        else if (curNum >= 5)
        {
            answer += 10 - curNum;
            storey += (10 - curNum) * curPow;
        }
        else
        {
            answer += curNum;
            storey -= curNum * curPow;
        }
    }
    
    if (storey != 0)
    {
        answer++;
    }
    
    return answer;
}