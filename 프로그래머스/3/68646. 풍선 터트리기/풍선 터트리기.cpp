#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int> leftMin(a.size());
    vector<int> rightMin(a.size());
    
    leftMin[0] = a[0];
    rightMin[a.size() - 1] = a[a.size() - 1];
    for (int i = 1; i < a.size(); i++)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
    }
    for (int i = a.size() - 2; i >= 0; i--)
    {
        rightMin[i] = min(rightMin[i + 1], a[i]);
    }
    
    answer = 2;
    
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (leftMin[i] < a[i] && rightMin[i] < a[i])
            continue;
        
        answer++;
    }
    
    return answer;
}