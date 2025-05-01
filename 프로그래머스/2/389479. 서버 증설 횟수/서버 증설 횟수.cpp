#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    vector<int> expandedServer(24);
    int curServer = 1;
    
    for (int i = 0; i < players.size(); i++)
    {
        if (i >= k)
        {
            curServer -= expandedServer[i - k];
        }
        
        if (players[i] >= curServer * m)
        {
            int expandCount = players[i] / m - (curServer - 1);
            expandedServer[i] += expandCount;
            curServer += expandCount;
            answer += expandCount;
        }
    }
    
    return answer;
}