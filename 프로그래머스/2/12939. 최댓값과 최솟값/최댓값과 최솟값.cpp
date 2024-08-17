#include <string>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

string solution(string s) {
    string answer;
    
    int length = s.length();
    
    string num = "";
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    
    for (int i = 0; i < length; i++)
    {
        if (s[i] == ' ')
        {
            int tempNum = stoi(num);
            num = "";
            
            if (minNum > tempNum)
            {
                minNum = tempNum;
            }
            if (maxNum < tempNum)
            {
                maxNum = tempNum;
            }
        }
        else
        {
            num += s[i];
        }
    }
    
    if (num != "")
    {
        int tempNum = stoi(num);
        if (minNum > tempNum)
        {
            minNum = tempNum;
        }
        if (maxNum < tempNum)
        {
            maxNum = tempNum;
        }
    }
    
    answer = to_string(minNum) + " " + to_string(maxNum);
    
    return answer;
}