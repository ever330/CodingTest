#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long nextNum(long long tempNum)
{
    int power = 0;
    int bin = tempNum % 2;
    tempNum /= 2;
    
    while (bin != 0)
    {
        power++;
        bin = tempNum % 2;
        tempNum /= 2;
    }
    
    if (power > 0)
    {
        return pow(2, power - 1);
    }
    else
    {
        return 1;
    } 
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long num : numbers)
    {
        answer.push_back(num + nextNum(num));
    }
    
    return answer;
}