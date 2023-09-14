#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int maxNum = n * (n + 1) / 2;
    
    vector<int> answer(maxNum);
    
    int index = 0;
    int next = 0;
    int count = 0;
    int target = n;
    int dir = 0;
    
    
    for (int i = 1; i <= maxNum; i++)
    {
        if (dir == 0)
        {
            index += next;
            answer[index] = i;
            next++;
        }
        else if (dir == 1)
        {
            index++;
            answer[index] = i;
        }
        else
        {
            index -= next;
            answer[index] = i;
            next--;
        }
        count++;
        if (count >= target)
        {
            count = 0;
            target--;
            dir++;
            if (dir >= 3)
                dir = 0;
        }
    }
    
    return answer;
}