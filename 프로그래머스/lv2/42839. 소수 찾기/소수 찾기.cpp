#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool IsPrimeNumber(int num)
{
    if (num == 0 || num == 1)
        return false;
    
    if (num == 2 || num == 3)
        return true;
    
    for (int i = 2; i <= (int)(sqrt(num)); i++)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    set<int> allNum;
    vector<int> sortedNum;
    
    for (int i = 0; i < numbers.length(); i++)
    {
        sortedNum.push_back(numbers[i] - '0');
    }
    
    for (int i = 1; i <= sortedNum.size(); i++)
    {
        sort(sortedNum.begin(), sortedNum.end());
        do
        {
            string temp;
            for (int j = 0; j < i; j++)
            {
                temp += to_string(sortedNum[j]);
            }
            allNum.insert(stoi(temp));
        } while(next_permutation(sortedNum.begin(), sortedNum.end()));   
    }
    
    for (int num : allNum)
    {
        if (IsPrimeNumber(num))
        {
            answer++;
        }
    }
    
    return answer;
}