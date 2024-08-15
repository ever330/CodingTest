#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer;
    
    vector<int> vec;
    int length = s.length();
    
    string num = "";
    for (int i = 0; i < length; i++)
    {
        if (s[i] == ' ')
        {
            vec.push_back(stoi(num));
            num = "";
        }
        else
        {
            num += s[i];
        }
    }
    
    if (num != "")
        vec.push_back(stoi(num));
    
    sort(vec.begin(), vec.end());
    
    cout << vec.size() << endl;
    answer = to_string(vec[0]) + " " + to_string(vec[vec.size() - 1]);
    
    return answer;
}