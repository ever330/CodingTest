#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = -1;
    
    answer = 0;
    string nowStr = "";

    for (auto i = 0; i < s.size(); i++)
    {
        nowStr.clear();
        if (s[0] != ')' && s[0] != '}' && s[0] != ']')
        {
            nowStr.push_back(s[0]);
            for (auto j = 1; j < s.size(); j++)
            {
                if (!nowStr.empty())
                {
                    if (nowStr.back() == '(' && s[j] == ')')
                    {
                        nowStr.pop_back();
                    }
                    else if (nowStr.back() == '[' && s[j] == ']')
                    {
                        nowStr.pop_back();
                    }
                    else if (nowStr.back() == '{' && s[j] == '}')
                    {
                        nowStr.pop_back();
                    }
                    else
                    {
                        nowStr.push_back(s[j]);
                    }
                }
                else
                {
                    nowStr.push_back(s[j]);
                }
            }
            if (nowStr.empty())
            {
                answer++;
            }
        }
        char frontChar = s.front();
        s.erase(0, 1);
        s.push_back(frontChar);
    }
    
    return answer;
}