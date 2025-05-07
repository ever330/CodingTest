#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool DistanceCheck(vector<string>& place, int x, int y)
{
    // 상하좌우
    int dx1[] = {0, 1, 0, -1};
    int dy1[] = {-1, 0, 1, 0};

    // 직선 거리 2
    int dx2[] = {0, 2, 0, -2};
    int dy2[] = {-2, 0, 2, 0};

    // 대각선
    int dx_diag[] = {-1, -1, 1, 1};
    int dy_diag[] = {-1, 1, -1, 1};

    // 1칸 거리
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx1[i], ny = y + dy1[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            if (place[ny][nx] == 'P')
                return false;
        }
    }

    // 2칸 직선 거리
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx2[i], ny = y + dy2[i];
        int mx = x + dx1[i], my = y + dy1[i];  // 중간 지점
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            if (place[ny][nx] == 'P' && place[my][mx] != 'X')
                return false;
        }
    }

    // 대각선
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx_diag[i], ny = y + dy_diag[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            if (place[ny][nx] == 'P') {
                if (!(place[y][nx] == 'X' && place[ny][x] == 'X'))
                    return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; i++)
    {
        bool isOK = true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (places[i][j][k] == 'P')
                {
                    isOK = DistanceCheck(places[i], k, j);
                    if (!isOK)
                    {
                        cout << "out" << endl;
                        break;
                    }
                    
                }
            }
            if (!isOK)
                break;
        }
        if (!isOK)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    
    return answer;
}