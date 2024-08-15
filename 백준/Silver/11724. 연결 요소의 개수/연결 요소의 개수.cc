#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int answer = 0;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(1001);
    bool visit[1001] = { false, };

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    answer++;
    visit[1] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int i : graph[temp])
        {
            if (!visit[i])
            {
                visit[i] = true;
                q.push(i);
            }
        }

        if (q.empty())
        {
            for (int i = 1; i <= n; i++)
            {
                if (!visit[i])
                {
                    visit[i] = true;
                    q.push(i);
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;

    return 0;
}