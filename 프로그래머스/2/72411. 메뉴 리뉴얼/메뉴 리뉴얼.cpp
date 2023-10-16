#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<string, int> a,
         pair<string, int> b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    
    for (int len : course)
    {
        map<string, int> order_com;
        for (string order : orders)
        {
            sort(order.begin(), order.end());

            if (order.length() == len)
            {
                order_com[order]++;
                continue;
            }
            else if (order.length() < len)
            {
                continue;
            }

            vector<bool> visited(order.length());
            for (int i = order.length() - 1; i > order.length() - len - 1; i--)
            {
                visited[i] = true;
            }
            do
            {
                string temp;
                for (int i = 0; i < order.length(); i++)
                {
                    if (visited[i])
                        temp += order[i];
                }
                order_com[temp]++;
            } while (next_permutation(visited.begin(), visited.end()));
        }
        
        if (order_com.empty())
            continue;
        
        vector<pair<string, int>> vec;
        for (auto& ord : order_com)
        {
            vec.push_back(ord);
        }
        sort(vec.begin(), vec.end(), compare);

        int maxCount = vec[0].second;
        if (maxCount >= 2)
        {
            for (auto& v : vec)
            {
                if (v.second < maxCount)
                    break;
                answer.push_back(v.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}