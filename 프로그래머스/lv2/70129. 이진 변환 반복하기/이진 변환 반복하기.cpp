#include <string>
#include <vector>

using namespace std;


string DecToBin(int num)
{
    string binNum;

    while (num != 1)
    {
        binNum.insert(0, to_string(num % 2));
        num /= 2;
    }
    binNum.insert(0, to_string(num));

    return binNum;
}

vector<int> solution(string s) 
{
    vector<int> answer = { 0, 0 };

    vector<int> eraseNum;

    while (s.size() != 1)
    {
        eraseNum.clear();
        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                eraseNum.push_back(i);
            }
        }
        for (auto i = eraseNum.size(); i > 0; i--)
        {
            s.erase(s.begin() + eraseNum[i - 1]);
            answer[1]++;
        }

        answer[0]++;
        s = DecToBin(s.size());
    }

    return answer;
}
