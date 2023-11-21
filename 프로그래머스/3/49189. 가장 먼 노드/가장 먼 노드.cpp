#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> edges[20001];
    bool visited[20001] = { false, };
    int depth[20001];
    
    for (int i = 0; i < edge.size(); i++)
    {
        edges[edge[i][0]].push_back(edge[i][1]);
        edges[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    depth[1] = 1;
    
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        
        for (int i = 0; i < edges[temp].size(); i++)
        {
            if (!visited[edges[temp][i]])
            {
                q.push(edges[temp][i]);
                depth[edges[temp][i]] = depth[temp] + 1;
                visited[edges[temp][i]] = true;
            }
        }
    }
    
    int maxDepth = depth[1];
    int count = 0;
    for (int i = 2; i <= 20000; i++)
    {
        if (maxDepth < depth[i])
        {
            maxDepth = depth[i];
            count = 1;
        }
        else if (maxDepth == depth[i])
        {
            count++;
        }
    }
    
    answer = count;
    
    return answer;
}