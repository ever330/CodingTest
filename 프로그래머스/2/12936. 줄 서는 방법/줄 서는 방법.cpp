#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n);
    
    for (int i = 0; i < n; i++)
        answer[i] = i + 1;
    
    long long per = 1;
    int index = 0; 
    
    while (n > 0) 
    {
        per = 1;
        for (int i = n - 1; i > 0; i--) 
        {
            per *= i;
        }

        if (k % per == 0) 
        {
            int now = k / per + index - 1;
            swap(answer[index], answer[now]);
            index++;
            sort(answer.begin() + index, answer.end(),greater<>());
            break;
        }
        else 
        {
            int now = k / per + index;
            swap(answer[index], answer[now]);
            index++;

            sort(answer.begin() + index, answer.end());
            k = k % per;
           
            n--;
        }
    }
    
    return answer;
}