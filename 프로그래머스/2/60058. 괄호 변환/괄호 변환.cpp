#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckCorrectString(const string& str)
{
    int count = 0;
    
    for (char c : str)
    {
        if (c == '(')
            count++;
        else
            count--;
        
        if (count < 0)
            return false;
    }
    
    return count == 0;
}

int StringDivide(const string& str)
{
    int count = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
            count++;
        else
            count--;
        if (count == 0)
            return i + 1;
    }
    return str.length();
}


string solution(string p) {
    if (p.empty())
        return "";
    
    int divideIndex = StringDivide(p);
    string u = p.substr(0, divideIndex);
    string v = p.substr(divideIndex);
    
    if (CheckCorrectString(u))
    {
        return u + solution(v);
    }
    else
    {
        string str = "(";
        str += solution(v);
        str += ")";
        u = u.substr(1, u.length() - 2);
        
        for (char& c : u)
        {
            if (c == '(')
                c = ')';
            else
                c = '(';
        }
        
        return str + u;
    }
}