#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int num1, int num2)
{
    string a = to_string(num1);
    string b = to_string(num2);
    
    if (a.length() == b.length())
    {
        return num1 > num2;
    }
    else
    {
        string sum1 = a + b;
        string sum2 = b + a;
        
        return stoi(sum1) > stoi(sum2);
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    int zeroCheck = 0;
    for (int num : numbers)
    {
        zeroCheck += num;
        answer += to_string(num);
    }
    
    if (zeroCheck == 0)
        answer = '0';
    
    return answer;
}