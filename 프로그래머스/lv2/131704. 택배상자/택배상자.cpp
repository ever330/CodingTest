#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    int nowIndex = 1;
    
    stack<int> subCon;
    for (int i = 0; i < order.size(); i++)
    {
        if (order[i] == nowIndex)
        {
            nowIndex++;
            answer++;
        }
        else
        {
            if (!subCon.empty() && order[i] == subCon.top())
            {
                subCon.pop();
                answer++;
            }
            else
            {
                if (nowIndex > order[i])
                    break;
                
                for (int j = nowIndex; j < order[i]; j++)
                {
                    subCon.push(j);
                    nowIndex++;
                }
                nowIndex++;
                answer++;
            }
        }
    }
    
    return answer;
}