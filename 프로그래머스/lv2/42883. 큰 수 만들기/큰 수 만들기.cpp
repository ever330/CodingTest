#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> numStack;
    int count = 0;

    for (int i = 0; i < number.length(); i++)
    {
        int nowNum = number[i] - '0';

        if (numStack.empty() || count >= k)
        {
            numStack.push(nowNum);
        }
        else
        {
            while (numStack.top() < nowNum)
            {
                numStack.pop();
                count++;
                if (count >= k || numStack.empty())
                {
                    break;
                }
            }
            numStack.push(nowNum);
        }
    }
    
    int maxSize = number.length() - k;
    while (numStack.size() > maxSize)
    {
        numStack.pop();
    }

    while (!numStack.empty())
    {
        answer.insert(0, to_string(numStack.top()));
        numStack.pop();
    }

    return answer;
}
