#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;

    sort(arr.begin(), arr.end());  
    int maxNum = arr.back();

    while (answer == 0)
    {
        for (auto i = 0; i < arr.size(); i++)
        {
            if (maxNum % arr[i] != 0)
            {
                maxNum++;
                break;
            }

            if (i == arr.size() - 1)
            {
                answer = maxNum;
            }
        }
    }

    return answer;
}