#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visited[100][100];

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    int startX = 0, startY = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                startX = j;
                startY = i;
                break;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({ startX, startY, 0 });
    visited[startY][startX] = true;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x;
            int ny = y;

            while (true) {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];

                if (tx < 0 || ty < 0 || tx >= m || ty >= n || board[ty][tx] == 'D')
                    break;

                nx = tx;
                ny = ty;
            }

            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;

            int nextX = nx + dx[dir];
            int nextY = ny + dy[dir];
            bool canStopAtG = (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || board[nextY][nextX] == 'D');

            if (board[ny][nx] == 'G' && canStopAtG)
                return cnt + 1;

            q.push({ nx, ny, cnt + 1 });
        }
    }

    return -1;
}