#include <string>
#include <vector>

using namespace std;

vector<int> QuadTree(vector<vector<int>>& arr, int posX, int posY, int length)
{
    int tempNum = arr[posY][posX];
    bool allCorrect = true;
    
    for (int y = posY; y < posY + length; y++)
    {
        for (int x = posX; x < posX + length; x++)
        {
            if (tempNum != arr[y][x])
            {
                allCorrect = false;
                break;
            }
        }
        if (!allCorrect)
            break;
    }
    vector<int> result(2);
    if (allCorrect)
    {
        result[tempNum] = 1;
    }
    else
    {
        if (length == 2)
        {
            for (int y = posY; y < posY + length; y++)
            {
                for (int x = posX; x < posX + length; x++)
                {
                    result[arr[y][x]]++;
                }
            }
        }
        else
        {
            vector<int> next1 = QuadTree(arr, posX, posY, length / 2);
            vector<int> next2 = QuadTree(arr, posX + length / 2, posY, length / 2);
            vector<int> next3 = QuadTree(arr, posX, posY + length / 2, length / 2);
            vector<int> next4 = QuadTree(arr, posX + length / 2, posY + length / 2, length / 2);
            
            result[0] = next1[0] + next2[0] + next3[0] + next4[0];
            result[1] = next1[1] + next2[1] + next3[1] + next4[1];
        }
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    answer = QuadTree(arr, 0, 0, arr.size());
    //vector<int> arr1 = QuadTree(arr, 0, 0, arr.size() / 2);
    //vector<int> arr2 = QuadTree(arr, arr.size() / 2, 0, arr.size() / 2);
    //vector<int> arr3 = QuadTree(arr, 0, arr.size() / 2, arr.size() / 2);
    //vector<int> arr4 = QuadTree(arr, arr.size() / 2, arr.size() / 2, arr.size() / 2);
    
    //answer.push_back(arr1[0] + arr2[0] + arr3[0] + arr4[0]);
    //answer.push_back(arr1[1] + arr2[1] + arr3[1] + arr4[1]);
    
    return answer;
}