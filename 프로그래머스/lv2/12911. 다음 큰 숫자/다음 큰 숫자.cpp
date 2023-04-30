#include <string>
#include <vector>

using namespace std;


int oneCount(string num)
{
    int one = 0;

    for (auto i = 0; i < num.size(); i++)
    {
        if (num[i] == '1')
        {
            one++;
        }
    }

    return one;
}

string DecToBin(int num)
{
    string s;

    while (num != 1)
    {
        s.insert(0, to_string(num % 2));
        num /= 2;
    }
    s.insert(s.begin(), 1);

    return s;
}

int solution(int n) 
{
    int answer = 0;

    string nBin = DecToBin(n);
    int one = oneCount(nBin);
    int nextOneCount = 0;
    answer = n;

    while (nextOneCount != one)
    {
        answer++;
        nextOneCount = oneCount(DecToBin(answer));
    }

    return answer;
}