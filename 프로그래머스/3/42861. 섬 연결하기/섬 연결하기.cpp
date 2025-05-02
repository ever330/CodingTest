#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[101];

bool Compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int FindParent(int num)
{
    if (parent[num] == num)
        return num;
    return FindParent(parent[num]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), Compare);
    
    for (int i = 0; i < costs.size(); i++)
    {
        if (parent[costs[i][0]] != parent[costs[i][1]])
        {
            int p1 = FindParent(costs[i][0]);
            int p2 = FindParent(costs[i][1]);
            
            if (p1 != p2) 
            {
                answer += costs[i][2];
                if (p1 < p2)
                    parent[p2] = p1;
                else
                    parent[p1] = p2;
            }

        }
    }
    
    return answer;
}