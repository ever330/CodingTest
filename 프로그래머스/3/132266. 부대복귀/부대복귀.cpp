#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n + 1);

    for (auto& road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    vector<int> dist(n + 1, 100001);
    vector<bool> visited(n + 1, false);
    
    queue<int> q;
    q.push(destination);
    visited[destination] = true;
    dist[destination] = 0;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        for (auto node : graph[curNode])
        {
            if (!visited[node])
            {
                if (dist[node] > dist[curNode] + 1)
                {
                    dist[node] = dist[curNode] + 1;
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
    }

    for (auto source : sources)
    {
        if (dist[source] != 100001)
        {
            answer.push_back(dist[source]);
        }
        else
        {
            answer.push_back(-1);
        }
    }
    
    return answer;
}