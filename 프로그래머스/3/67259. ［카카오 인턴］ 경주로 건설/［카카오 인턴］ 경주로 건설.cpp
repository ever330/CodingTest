#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

enum Direction : short 
{
    Horizontal,
    Vertical,
    None
};

struct Position
{
    int x;
    int y;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    vector<vector<vector<int>>> costs(n, vector<vector<int>>(n, vector<int>(2, 100000000)));
    
    queue<tuple<Position, Direction, int>> q;
    q.push({{0, 0}, None, 0});
    costs[0][0][Horizontal] = 0;
    costs[0][0][Vertical] = 0;
    
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    while (!q.empty())
    {
        auto [curPos, curLine, curCost] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nextX = curPos.x + dx[i];
            int nextY = curPos.y + dy[i];
            
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || board[nextY][nextX] == 1)
                continue;
            
            Direction newLine = (i == 0 || i == 2) ? Horizontal : Vertical;
            int newCost = curCost + 100;
            if (curLine != None && curLine != newLine) 
            {
                newCost += 500;
            }
            
            if (costs[nextY][nextX][newLine] > newCost) 
            {
                costs[nextY][nextX][newLine] = newCost;
                q.push({{nextX, nextY}, newLine, newCost});
            }
        }
    }
    
    answer = min(costs[n - 1][n - 1][Horizontal], costs[n - 1][n - 1][Vertical]);
    
    return answer;
}