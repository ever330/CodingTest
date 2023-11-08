#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    unordered_map<int, vector<int>> root;
    bool visited[200000] = { false };
    unordered_map<int, int> key;
    unordered_map<int, int> needKey;
    unordered_map<int, int> retry;
    set<int> hold;

    for (int i = 0; i < order.size(); i++)
    {
        if (order[i][1] == 0)
            return false;
        key.insert({ order[i][0], order[i][1] });
        needKey.insert({ order[i][1], order[i][0] });
    }

    for (int i = 0; i < path.size(); i++)
    {
        if (root.find(path[i][0]) == root.end())
        {
            vector<int> newVec;
            newVec.push_back(path[i][1]);
            root.insert({ path[i][0], newVec });
        }
        else
        {
            root[path[i][0]].push_back(path[i][1]);
        }

        if (root.find(path[i][1]) == root.end())
        {
            vector<int> newVec;
            newVec.push_back(path[i][0]);
            root.insert({ path[i][1], newVec });
        }
        else
        {
            root[path[i][1]].push_back(path[i][0]);
        }
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        needKey[key[temp]] = 0;

        if (hold.find(key[temp]) != hold.end())
        {
            hold.erase(key[temp]);
            q.push(key[temp]);
            visited[key[temp]] = true;
        }

        for (int i = 0; i < root[temp].size(); i++)
        {
            if (visited[root[temp][i]])
                continue;
            if (needKey[root[temp][i]] != 0)
            {
                hold.insert(root[temp][i]);
                continue;
            }
            visited[root[temp][i]] = true;
            q.push(root[temp][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }

    answer = true;

    return answer;
}