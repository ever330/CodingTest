#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
	
	answer = 1;
	while (!priorities.empty())
	{
		int nowNum = 0;
		int popIndex = 0;

		for (auto i = 0; i < priorities.size(); i++)
		{
			if (priorities[i] > nowNum)
			{
				nowNum = priorities[i];
				popIndex = i;
			}
		}

		if (location == popIndex)
		{
			break;
		}
		else
		{
			answer++;
		}

		if (popIndex > 0)
		{
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
		else
		{
			priorities.erase(priorities.begin());
			location--;
			if (location < 0)
			{
				location = priorities.size() - 1;
			}
		}
		
	}
    return answer;
}