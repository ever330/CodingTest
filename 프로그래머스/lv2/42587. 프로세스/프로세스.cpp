#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
	
	answer = 1;
	while (!priorities.empty())
	{
		int nowNum = 0;
		int popIndex = 0;

		popIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin();

		if (location == popIndex)
		{
			break;
		}
		else
		{
			answer++;
		}

		for (auto i = 0; i <= popIndex; i++)
		{
			if (i == popIndex)
			{
				priorities.erase(priorities.begin());
			}
			else
			{
				int popNum = priorities.front();
				priorities.erase(priorities.begin());
				priorities.push_back(popNum);
			}
			location--;
			if (location < 0)
			{
				location = priorities.size() - 1;
			}
		}

	}
    return answer;
}