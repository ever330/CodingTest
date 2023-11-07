#include <string>
#include <vector>

using namespace std;

struct Block
{
    int sx;
    int sy;
    int ex;
    int ey;
    int dx[2];
    int dy[2];
    bool isRemoved;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    vector<Block> blocks;
    
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            int tempNum = board[y][x];
            
            if (tempNum == 0)
                continue;
            
            if (y < board.size() - 2 && x < board.size() - 1)
            {
                if (board[y + 1][x] == tempNum && board[y + 2][x] == tempNum && board[y + 2][x + 1] == tempNum)
                {
                    Block newBlock;
                    newBlock.sx = x;
                    newBlock.sy = y;
                    newBlock.ex = x + 1;
                    newBlock.ey = y + 2;
                    newBlock.dx[0] = x + 1;
                    newBlock.dx[1] = x + 1;
                    newBlock.dy[0] = y;
                    newBlock.dy[1] = y + 1;
                    blocks.push_back(newBlock);
                    newBlock.isRemoved = false;
                    
                    continue;
                }
            }
            
            if (y < board.size() - 1 && x > 1)
            {
                if (board[y + 1][x] == tempNum && board[y + 1][x - 1] == tempNum && board[y + 1][x - 2] == tempNum)
                {
                    Block newBlock;
                    newBlock.sx = x - 2;
                    newBlock.sy = y;
                    newBlock.ex = x;
                    newBlock.ey = y + 1;
                    newBlock.dx[0] = x - 2;
                    newBlock.dx[1] = x - 1;
                    newBlock.dy[0] = y;
                    newBlock.dy[1] = y;
                    blocks.push_back(newBlock);
                    newBlock.isRemoved = false;
                    
                    continue;
                }
            }
            
            if (y < board.size() - 1 && x < board.size() - 2)
            {
                if (board[y + 1][x] == tempNum && board[y + 1][x + 1] == tempNum && board[y + 1][x + 2] == tempNum)
                {
                    Block newBlock;
                    newBlock.sx = x;
                    newBlock.sy = y;
                    newBlock.ex = x + 2;
                    newBlock.ey = y + 1;
                    newBlock.dx[0] = x + 1;
                    newBlock.dx[1] = x + 2;
                    newBlock.dy[0] = y;
                    newBlock.dy[1] = y;
                    blocks.push_back(newBlock);
                    newBlock.isRemoved = false;
                    
                    continue;
                }
            }
            
            if (y < board.size() - 2 && x > 0)
            {
                if (board[y + 1][x] == tempNum && board[y + 2][x] == tempNum && board[y + 2][x - 1] == tempNum)
                {
                    Block newBlock;
                    newBlock.sx = x - 1;
                    newBlock.sy = y;
                    newBlock.ex = x;
                    newBlock.ey = y + 2;
                    newBlock.dx[0] = x - 1;
                    newBlock.dx[1] = x - 1;
                    newBlock.dy[0] = y;
                    newBlock.dy[1] = y + 1;
                    blocks.push_back(newBlock);
                    newBlock.isRemoved = false;
                    
                    continue;
                }
            }
            
            if (y < board.size() - 1 && x > 0 && x < board.size() - 1)
            {
                if (board[y + 1][x] == tempNum && board[y + 1][x + 1] == tempNum && board[y + 1][x - 1] == tempNum)
                {
                    Block newBlock;
                    newBlock.sx = x - 1;
                    newBlock.sy = y;
                    newBlock.ex = x + 1;
                    newBlock.ey = y + 1;
                    newBlock.dx[0] = x - 1;
                    newBlock.dx[1] = x + 1;
                    newBlock.dy[0] = y;
                    newBlock.dy[1] = y;
                    blocks.push_back(newBlock);
                    newBlock.isRemoved = false;
                    
                    continue;
                }
            }
        }
    }
    
    bool hasRemovable = true;
    
    while (hasRemovable)
    {
        hasRemovable = false;
        
        for (int i = 0; i < blocks.size(); i++)
        {
            if (blocks[i].isRemoved)
                continue;
            
            if (board[blocks[i].dy[0]][blocks[i].dx[0]] == 0 && board[blocks[i].dy[1]][blocks[i].dx[1]] == 0)
            {
                bool cantRemove = false;
                for (int y = 0; y < blocks[i].sy; y++)
                {
                    if (board[y][blocks[i].dx[0]] != 0 || board[y][blocks[i].dx[1]] != 0)
                        cantRemove = true;
                }
                if (cantRemove)
                    continue;
                
                answer++;
                hasRemovable = true;
                blocks[i].isRemoved = true;
                for (int y = blocks[i].sy; y <= blocks[i].ey; y++)
                {
                    for (int x = blocks[i].sx; x <= blocks[i].ex; x++)
                    {
                        board[y][x] = 0;
                    }
                }
            }
        }
    }
    
    return answer;
}