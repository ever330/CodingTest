#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100][100];
int m, n = 0;

int DFS(vector<string> maps, int x, int y)
{
    int dx[4] = { 1, 0, -1, 0};
    int dy[4] = { 0, 1, 0, -1};
    
    int count = maps[y][x] - '0';
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
            continue;
        
        if (maps[nextY][nextX] != 'X' && !visited[nextY][nextX])
        {
            count += DFS(maps, nextX, nextY);
        }
    }
    
    return count;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    m = maps[0].size();
    n = maps.size();
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'X' && !visited[i][j])
            {
                int count = DFS(maps, j, i);
                answer.push_back(count);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.empty())
        answer.push_back(-1);
    
    return answer;
}