#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string PlusStr(const string& str)
{
    string result = "";
    
    string num1 = "";
    string num2 = "";
    bool isPlus = false;
    
    for (auto c : str)
    {
        if (c == '-' && num1.empty() && !isPlus)
        {
            num1 += c;
        }
        else if (c == '-' && num2.empty() && isPlus)
        {
            num2 += c;
        }
        else if (c == '+' && !isPlus)
        {
            isPlus = true;
        }
        else if (c == '+' && isPlus)
        {
            long long n = stoll(num1) + stoll(num2);
            num1 = to_string(n);
            num2 = "";
        }
        else if ((c == '-' || c == '*') && isPlus)
        {
            long long n = stoll(num1) + stoll(num2);
            result += to_string(n);
            result += c;
            num1 = "";
            num2 = "";
            isPlus = false;
        }
        else if ((c == '-' || c == '*') && !isPlus)
        {
            result += num1;
            result += c;
            num1 = "";
        }
        else
        {
            if (!isPlus)
                num1 += c;
            else
                num2 += c;
        }
    }
    
    if (isPlus)
    {
        long long n = stoll(num1) + stoll(num2);
        result += to_string(n);
    }
    else
    {
        result += num1;
    }
    
    return result;
}

string MultiStr(const string& str)
{
    string result = "";
    
    string num1 = "";
    string num2 = "";
    bool isMulti = false;
    
    for (auto c : str)
    {
        if (c == '-' && num1.empty() && !isMulti)
        {
            num1 += c;
        }
        else if (c == '-' && num2.empty() && isMulti)
        {
            num2 += c;
        }
        else if (c == '*' && !isMulti)
        {
            isMulti = true;
        }
        else if (c == '*' && isMulti)
        {
            long long n = stoll(num1) * stoll(num2);
            num1 = to_string(n);
            num2 = "";
        }
        else if ((c == '+' || c == '-') && isMulti)
        {
            long long n = stoll(num1) * stoll(num2);
            result += to_string(n);
            result += c;
            num1 = "";
            num2 = "";
            isMulti = false;
        }
        else if ((c == '+' || c == '-') && !isMulti)
        {
            result += num1;
            result += c;
            num1 = "";
        }
        else
        {
            if (!isMulti)
                num1 += c;
            else
                num2 += c;
        }
    }
    
    if (isMulti)
    {
        long long n = stoll(num1) * stoll(num2);
        result += to_string(n);
    }
    else
    {
        result += num1;
    }
    
    return result;
}

string MinusStr(const string& str)
{
    string result = "";
    
    string num1 = "";
    string num2 = "";
    bool isMinus = false;
    
    for (auto c : str)
    {
        if (c == '-' && !isMinus)
        {
            isMinus = true;
        }
        else if (c == '-' && isMinus)
        {
            long long n = stoll(num1) - stoll(num2);
            num1 = to_string(n);
            num2 = "";
        }
        else if ((c == '+' || c == '*') && isMinus)
        {
            long long n = stoll(num1) - stoll(num2);
            result += to_string(n);
            result += c;
            num1 = "";
            num2 = "";
            isMinus = false;
        }
        else if ((c == '+' || c == '*') && !isMinus)
        {
            result += num1;
            result += c;
            num1 = "";
        }
        else
        {
            if (!isMinus)
                num1 += c;
            else
                num2 += c;
        }
    }
    
    if (isMinus)
    {
        long long n = stoll(num1) - stoll(num2);
        result += to_string(n);
    }
    else
    {
        result += num1;
    }
    
    return result;
}

long long solution(string expression) {
    long long answer = 0;
    
    long long temp = 0;
    string s1 = PlusStr(MinusStr(MultiStr(expression)));
    answer = stoll(s1);
    string s2 = PlusStr(MultiStr(MinusStr(expression)));
    temp = abs(stoll(s2));
    answer = answer < temp ? temp : answer;
    string s3 = MinusStr(PlusStr(MultiStr(expression)));
    temp = abs(stoll(s3));
    answer = answer < temp ? temp : answer;
    string s4 = MinusStr(MultiStr(PlusStr(expression)));
    temp = abs(stoll(s4));
    answer = answer < temp ? temp : answer;
    string s5 = MultiStr(PlusStr(MinusStr(expression)));
    temp = abs(stoll(s5));
    answer = answer < temp ? temp : answer;
    string s6 = MultiStr(MinusStr(PlusStr(expression)));
    temp = abs(stoll(s6));
    answer = answer < temp ? temp : answer;
    
    //cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6;
    
    return answer;
}