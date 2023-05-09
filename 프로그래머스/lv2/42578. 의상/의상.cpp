#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector<pair<string, int>> kinds;

	for (auto i = 0; i < clothes.size(); i++)
	{
		if (kinds.empty())
		{
			kinds.push_back(make_pair(clothes[i][1], 1));
		}
		else
		{
			bool isExist = false;
			for (auto j = 0; j < kinds.size(); j++)
			{
				if (kinds[j].first == clothes[i][1])
				{
					kinds[j].second += 1;
					isExist = true;
					break;
				}
			}
			if (!isExist)
			{
				kinds.push_back(make_pair(clothes[i][1], 1));
			}
		}
	}

	answer = 1;
	for (auto i = 0; i < kinds.size(); i++)
	{
		answer *= kinds[i].second + 1;
	}
	answer--;
    return answer;
}