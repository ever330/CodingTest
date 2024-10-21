#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    if (arrayA.size() == 1)
    {
        int startNum = max(arrayA[0], arrayB[0]);
        bool canDevideA = false;
        bool canDevideB = false;

        int maxNum = 0;
        for (int i = startNum; i > 0; i--)
        {
            if (arrayA[0] % i == 0)
                canDevideA = true;
            if (arrayB[0] % i == 0)
                canDevideB = true;

            if (canDevideA != canDevideB)
            {
                maxNum = i;
                break;
            }
        }
        return maxNum;
    }
    
    sort(arrayA.begin(), arrayA.end());   
    sort(arrayB.begin(), arrayB.end());
    
    int maxA = 0;
    
    for (int i = arrayA[0]; i > 0; i--)
    {
        bool prevDevideA = false;
        bool prevDevideB = false;
        
        if (arrayA[0] % i == 0)
            prevDevideA = true;
        if (arrayB[0] % i == 0)
            prevDevideB = true;
        
        if (prevDevideA == prevDevideB)
            continue;
        
        for (int j = 0; j < arrayA.size(); j++)
        {
            bool curDevideA = false;
            bool curDevideB = false;
            
            if (arrayA[j] % i == 0)
                curDevideA = true;
            if (arrayB[j] % i == 0)
                curDevideB = true;
            
            if ((prevDevideA != curDevideA) || (prevDevideB != curDevideB))
                break;
        
            if (j == arrayA.size() - 1)
                maxA = i;
        }
        
        if (maxA != 0)
            break;
    }
    answer = maxA;
    
    return answer;
}