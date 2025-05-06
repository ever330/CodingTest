#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int arr[rows + 1][columns + 1];
    
    int count = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            arr[i][j] = count++;
        }
    }
    
    for (auto& v : queries)
    {
        int r = v[2] - v[1] + 1;
        int c = v[3] - v[0] + 1;
        int count = r * c - (r - 2) * (c - 2);
        
        int curX = v[0];
        int curY = v[1];
        int next = arr[v[0]][v[1]];
        int min = next;
        for (int i = 0; i < count; i++)
        {
            int temp = 0;
            if (curX == v[0] && curY >= v[1] && curY < v[3])
            {
                curY++;
            }
            else if (curY == v[3] && curX >= v[0] && curX < v[2])
            {
                curX++;
            }
            else if (curX == v[2] && curY > v[1] && curY <= v[3])
            {
                curY--;
            }
            else
            {
                curX--;
            }
            
            temp = arr[curX][curY];
            arr[curX][curY] = next;
            next = temp;
            if (min > next)
                min = next;
        }
        
        answer.push_back(min);
    }
    
    return answer;
}