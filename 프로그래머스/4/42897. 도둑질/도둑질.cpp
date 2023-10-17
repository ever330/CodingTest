#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    vector<int> moneyV1(1);
    vector<int> moneyV2(1);
    vector<int> moneySum1(money.size());
    vector<int> moneySum2(money.size());
    
    for (int i = 0; i < money.size() - 1; i++)
    {
        moneyV1.push_back(money[i]);
    }
    for (int i = 1; i < money.size(); i++)
    {
        moneyV2.push_back(money[i]);
    }
    
    moneySum1[0] = moneyV1[0];
    moneySum2[0] = moneyV2[0];
    moneySum1[1] = moneyV1[1];
    moneySum2[1] = moneyV2[1];
    moneySum1[2] = max(moneyV1[1], moneyV1[2]);
    moneySum2[2] = max(moneyV2[1], moneyV2[2]);
    
    if (money.size() == 3)
    {
        answer = max(max(money[0], money[1]), money[2]);
    }
    else
    {
        for (int i = 3; i < money.size(); i++)
        {
            moneySum1[i] = max(moneySum1[i - 1], moneySum1[i - 2] + moneyV1[i]);
            moneySum2[i] = max(moneySum2[i - 1], moneySum2[i - 2] + moneyV2[i]);
        }
        answer = max(moneySum1[money.size() - 1], moneySum2[money.size() - 1]);
    }
    
    return answer;
}