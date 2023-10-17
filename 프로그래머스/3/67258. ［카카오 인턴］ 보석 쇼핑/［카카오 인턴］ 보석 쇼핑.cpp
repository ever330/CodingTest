#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    int kindCount = 0;
    set<string> kind;
    for (string gem : gems)
    {
        kind.insert(gem);
    }
    kindCount = kind.size();
    
    map<string, int> gemCount;
    int startIndex = 0;
    int endIndex = 0;
    int minCount = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        if (gemCount.find(gems[i]) == gemCount.end())
        {
            gemCount.insert(pair<string, int>(gems[i], 1));
        }
        else
        {
            gemCount[gems[i]]++;
        }
        
        endIndex = i;
        
        for (int j = startIndex; j < endIndex; j++)
        {
            if (gemCount[gems[j]] <= 1)
            {
                break;
            }
            else
            {
                startIndex++;
                gemCount[gems[j]]--;
            }
        }
        
        if (gemCount.size() == kindCount)
        {
            int tempCount = endIndex - startIndex + 1;
            if (tempCount == kindCount)
            {
                answer[0] = startIndex + 1;
                answer[1] = endIndex + 1;
                break;
            }
            
            if (minCount == 0 || tempCount < minCount)
            {
                answer[0] = startIndex + 1;
                answer[1] = endIndex + 1;
                minCount = tempCount;
            }
        }
    }
    
    return answer;
}