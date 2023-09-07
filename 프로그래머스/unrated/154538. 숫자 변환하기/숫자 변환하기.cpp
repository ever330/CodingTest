#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<pair<int, int>> count;
    
    count.push(make_pair(y, 0));
    
    while (!count.empty())
    {
        pair<int, int> tempCount = count.front();
        count.pop();
        
        if (tempCount.first == x)
        {
            if (answer == -1)
            {
                answer = tempCount.second;
            }
            else
            {
                answer = min(tempCount.second, answer);
            }
        }
        else if (tempCount.first > x)
        {
            if (tempCount.first % 3 == 0 && (answer == -1 || answer > tempCount.second + 1))
                count.push(make_pair(tempCount.first / 3, tempCount.second + 1));
            
            if (tempCount.first % 2 == 0 && (answer == -1 || answer > tempCount.second + 1))
                count.push(make_pair(tempCount.first / 2, tempCount.second + 1));
            
            if (answer == -1 || answer > tempCount.second + 1)
                count.push(make_pair(tempCount.first - n, tempCount.second + 1));
        }
    }
    
    return answer;
}