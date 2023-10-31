#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int maxSum = 0;
    
    for (int i = 0; i < cookie.size(); i++)
    {
        maxSum += cookie[i];
    }
    maxSum /= 2;
    
    for (int i = 0; i < cookie.size(); i++)
    {
        int leftSum = 0;
        int rightSum = cookie[i];
        
        int leftPoint = i;
        int rightPoint = i;
        while (leftPoint >= 0 && rightPoint <= cookie.size() - 1)
        {
            if (leftSum == rightSum)
            {
                answer = max(answer, leftSum);
            }
            
            if (leftSum <= rightSum)
            {
                leftPoint--;
                if (leftPoint < 0)
                    break;
                leftSum += cookie[leftPoint];
            }
            else if (leftSum > rightSum)
            {
                rightPoint++;
                if (rightPoint > cookie.size() - 1)
                    break;
                rightSum += cookie[rightPoint];
            }
        }
        if (answer == maxSum)
            break;
    }
    
    return answer;
}