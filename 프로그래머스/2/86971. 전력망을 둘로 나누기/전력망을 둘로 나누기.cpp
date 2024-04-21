#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, int pass, vector<vector<int>> linked)
{
    int result = 1;
    queue<int> q;
    vector<int> visited(linked.size() + 1, false);
    visited[start] = true;

    for (int i = 0; i < linked[start].size(); i++)
    {
        if (!visited[linked[start][i]] && linked[start][i] != pass)
        {
            q.push(linked[start][i]);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        visited[temp] = true;
        q.pop();
        result++;

        for (int i = 0; i < linked[temp].size(); i++)
        {
            if (!visited[linked[temp][i]] && linked[temp][i] != pass)
            {
                q.push(linked[temp][i]);
            }
        }
    }

    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999999;
    vector<vector<int>> linked(n + 1);

    for (int i = 0; i < wires.size(); i++)
    {
        linked[wires[i][0]].push_back(wires[i][1]);
        linked[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int a = bfs(wires[i][0], wires[i][1], linked);
        int b = bfs(wires[i][1], wires[i][0], linked);
        answer = min(abs(a - b), answer);
    }

    return answer;
}