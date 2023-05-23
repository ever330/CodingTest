#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (auto i = 0; i < prices.size(); i++)
	{
		int sec = 0;
		if (i == prices.size() - 1)
		{
			answer.emplace_back(sec);
			break;
		}
		for (auto j = i + 1; j < prices.size(); j++)
		{
			sec++;
			if (prices[i] > prices[j])
			{
				answer.emplace_back(sec);
				break;
			}
			if (j == prices.size() - 1)
			{
				answer.emplace_back(sec);
				break;
			}
		}
	}
    return answer;
}