#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000000;
    
    deque<pair<int, int>> dq;
    for (int i = 0; i < stones.size(); i++)
    {
        while (!dq.empty() && dq.front().second < i - k + 1) 
            dq.pop_front();
        
        while (!dq.empty() && dq.back().first < stones[i]) 
            dq.pop_back();
        
        dq.push_back(make_pair(stones[i], i));
        
        if (i >= k - 1 && dq.front().first < answer) 
            answer = dq.front().first;
    }
    
    return answer;
}