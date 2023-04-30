#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> useWords;

    answer.push_back(0);    
    answer.push_back(0);

    for (auto i = 0; i < words.size(); i++)
    {
        if (i > 0)
        {
            if (words[i - 1].back() != words[i].front())
            {
                answer.clear();
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                break;
            }
        }

        if (find(useWords.begin(), useWords.end(), words[i]) == useWords.end())
        {
            useWords.push_back(words[i]);
        }
        else
        {
            answer.clear();
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return answer;
}