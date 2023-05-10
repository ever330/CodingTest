#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	vector<bool> clearList(progresses.size());
	int checkCount = 0;

	while (checkCount != progresses.size())
	{
		for (auto i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}

		int count = 0;

		for (auto i = 0; i < progresses.size(); i++)
		{
			if (progresses[i] >= 100 && !clearList[i])
			{
				count++;
				clearList[i] = true;
				checkCount++;
			}
			else if (progresses[i] < 100 && !clearList[i])
			{
				break;
			}
		}

		if (count > 0)
		{
			answer.push_back(count);
		}
	}
    return answer;
}