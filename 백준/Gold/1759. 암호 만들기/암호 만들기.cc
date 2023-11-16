#include <bits/stdc++.h>

using namespace std;

vector<char> AlphabetVec;
vector<string> Codes;
int L, C;

void CodeSearch(string tempCode, int tempIndex)
{
    for (int i = tempIndex + 1; i < C; i++)
    {
        string code;
        code += tempCode;
        code += AlphabetVec[i];
        if (code.length() < L)
            CodeSearch(code, i);
        else
            Codes.push_back(code);
    }
}

bool CodeCheck(string code)
{
    int vCnt = 0;
    int cCnt = 0;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u')
        {
            vCnt++;
        }
        else
        {
            cCnt++;
        }
        if (vCnt >= 1 && cCnt >= 2)
            return true;
    }
    return false;
}

int main()
{
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        char c;
        cin >> c;
        AlphabetVec.push_back(c);
    }
    sort(AlphabetVec.begin(), AlphabetVec.end());

    for (int i = 0; i <= C - L; i++)
    {
        string temp;
        temp += AlphabetVec[i];
        CodeSearch(temp, i);
    }
    vector<string> result;
    for (auto& code : Codes)
    {
        if (CodeCheck(code))
            result.push_back(code);
    }

    for (auto& code : result)
    {
        cout << code << endl;
    }

    return 0;
}