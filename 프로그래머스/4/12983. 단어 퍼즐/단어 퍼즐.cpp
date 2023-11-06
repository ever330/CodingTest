#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXNUM = 1000000000;

bool compare(string a, string b)
{
    return a.length() < b.length();
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int dp[20001];
    fill_n(dp, 20001, MAXNUM);
    
    sort(strs.begin(), strs.end(), compare);

    string tempStr = "";
    for (int i = 0; i < t.length(); i++)
    {
        tempStr += t[i];

        for (auto str : strs)
        {
            if (tempStr == str)
            {
                dp[i] = 1;
                break;
            }
            
            if (i + 1 < str.length())
                break;

            bool isSame = true;
            for (int j = 1; j <= str.length(); j++)
            {
                if (str[str.length() - j] != tempStr[tempStr.length() - j])
                {
                    isSame = false;
                    break;
                }
            }
            if (!isSame)
                continue;
            
            dp[i] = min(dp[i], dp[tempStr.length() - str.length() - 1] + 1);
        }
    }
    
    dp[t.length() - 1] == MAXNUM ? answer = -1 : answer = dp[t.length() - 1];
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}