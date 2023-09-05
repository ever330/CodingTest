#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Position
{
    int x;
    int y;
};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool hasDelete = true;
    
    while (hasDelete)
    {
        vector<Position> deletePos;
        for (int y = 0; y < m - 1; y++)
        {
            for (int x = 0; x < n - 1; x++)
            {
                if (board[y][x] == ' ')
                    continue;
                
                if (board[y][x] == board[y][x + 1] && board[y][x] == board[y + 1][x] && board[y][x] == board[y + 1][x + 1])
                {
                    Position pos;
                    pos.x = x;
                    pos.y = y;
                    deletePos.push_back(pos);
                }
            }
        }
        
        if (deletePos.empty())
        {
            hasDelete = false;
        }
        else
        {
            for (auto pos : deletePos)
            {
                board[pos.y][pos.x] = ' ';
                board[pos.y][pos.x + 1] = ' ';
                board[pos.y + 1][pos.x] = ' ';
                board[pos.y + 1][pos.x + 1] = ' ';
            }
            
            for (int x = 0; x < n; x++)
            {
                stack<char> word;
                for (int y = 0; y < m; y++)
                {
                    if (board[y][x] != ' ')
                    {
                        word.push(board[y][x]);
                        board[y][x] = ' ';
                    }
                }

                int count = word.size();
                for (int i = 1; i <= count; i++)
                {
                    board[m - i][x] = word.top();
                    word.pop();
                }
            }
        }
    }
    
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (board[y][x] == ' ')
            {
                answer++;
            }
        }
    }
    
    return answer;
}