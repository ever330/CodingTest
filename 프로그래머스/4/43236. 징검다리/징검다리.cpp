#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    vector<int> rockDis;
    rockDis.push_back(rocks[0]);
    for (int i = 1; i < rocks.size(); i++)
    {
        rockDis.push_back(rocks[i] - rocks[i - 1]);
    }
    rockDis.push_back(distance - rocks[rocks.size() - 1]);
    
    int reft = 0;
    int right = distance + 1;
    
    while (reft < right)
    {
        int mid = (reft + right) / 2;
        
        int remove = 0;
        int tempDis = 0;
        for (int i = 0; i < rockDis.size(); i++)
        {
            tempDis += rockDis[i];
            
            if (tempDis < mid)
            {
                remove++;
            }
            else
            {
                tempDis = 0;
            }
        }
        
        if (remove > n)
        {
            right = mid;
        }
        else
        {
            reft = mid + 1;
        }
    }
    
    answer = reft - 1;
    
    return answer;
}