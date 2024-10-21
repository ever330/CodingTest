#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[101][101];
int dist[101][101];

bool visitedE[101][101];
int distE[101][101];

int bfs(vector<string>& maps, int startY, int startX, int endY, int endX, bool visited[][101], int dist[][101]) {
    const int y = maps.size();
    const int x = maps[0].length();
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    queue<pair<int, int>> q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;
    dist[startY][startX] = 0;
    
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if (nextX < 0 || nextX >= x || nextY < 0 || nextY >= y)
                continue;
            if (maps[nextY][nextX] == 'X')
                continue;
            if (visited[nextY][nextX])
                continue;
            
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
            dist[nextY][nextX] = dist[curY][curX] + 1;
            
            if (nextY == endY && nextX == endX)
                return dist[nextY][nextX];
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    const int y = maps.size();
    const int x = maps[0].length();
    
    int start[2] = {0, 0};
    int lever[2] = {0, 0};
    int exit[2] = {0, 0};
    
    // 출발점, 레버, 출구 위치 찾기
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (maps[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            }
            if (maps[i][j] == 'L') {
                lever[0] = i;
                lever[1] = j;
            }
            if (maps[i][j] == 'E') {
                exit[0] = i;
                exit[1] = j;
            }
        }
    }
    
    // 출발점에서 레버까지 거리 구하기
    int toLever = bfs(maps, start[0], start[1], lever[0], lever[1], visited, dist);
    if (toLever == -1)
        return -1; // 레버까지 갈 수 없으면 탈출 불가
    
    // 레버에서 출구까지 거리 구하기
    int toExit = bfs(maps, lever[0], lever[1], exit[0], exit[1], visitedE, distE);
    if (toExit == -1)
        return -1; // 출구까지 갈 수 없으면 탈출 불가
    
    return toLever + toExit; // 총 시간 반환
}