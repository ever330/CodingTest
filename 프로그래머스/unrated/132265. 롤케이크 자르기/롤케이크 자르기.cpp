#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> leftToppingCount(topping.size());
    vector<int> rightToppingCount(topping.size());
    
    set<int> leftSet;
    set<int> rightSet;
    
    for (int i = 0; i < topping.size(); i++)
    {
        leftSet.insert(topping[i]);
        leftToppingCount[i] = leftSet.size();
    }
    for (int i = topping.size() - 1; i >= 0; i--)
    {
        rightSet.insert(topping[i]);
        rightToppingCount[i] = rightSet.size();
    }
    
    for (int i = 0; i < topping.size() - 1; i++)
    {
        if (leftToppingCount[i] == rightToppingCount[i + 1])
        {
            answer++;
        }
    }
    
    return answer;
}