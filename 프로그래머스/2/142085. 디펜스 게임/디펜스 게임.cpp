#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    if (k >= enemy.size())
        return enemy.size();
    
    priority_queue<int> pq;
    
    for (int e : enemy)
    {
        if (n >= e)
        {
            n -= e;
            answer++;
            pq.push(e);
        }
        else if (n < e && k > 0)
        {
            if (pq.empty())
            {
                k--;
                answer++;
                continue;
            }
                
            if (pq.top() > e)
            {
                n += pq.top();
                pq.pop();
                k--;
                n -= e;
                pq.push(e);
            }
            else
            {
                k--;
            }
            answer++;
        }
        else
        {
            break;
        }
    }

    return answer;
}