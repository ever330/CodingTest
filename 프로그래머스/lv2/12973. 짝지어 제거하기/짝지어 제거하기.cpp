#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> sameCheck;

    for (auto i = 0; i < s.size(); i++)
    {
        if (sameCheck.size() >= 1)
        {
            if (sameCheck.top() == s[i])
            {
                sameCheck.pop();
            }
            else
            {
                sameCheck.push(s[i]);
            }
        }
        else
        {
            sameCheck.push(s[i]);
        }
    }
    sameCheck.empty() ? answer = 1 : answer = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}