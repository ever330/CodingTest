#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

	if (find(words.begin(), words.end(), target) == words.end())
	{
		return answer;
	}

	int targetIndex = find(words.begin(), words.end(), target) - words.begin();
	queue<int> wordQ;
	vector<bool> visited(words.size(), false);
	vector<int> distance(words.size(), 0);

	for (int i = 0; i < words.size(); i++)
	{
		int difCount = 0;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (begin[j] != words[i][j])
			{
				difCount++;
			}
			if (difCount > 1)
				break;
		}

		if (difCount == 1)
		{
			visited[i] = true;
			distance[i] = 1;
			wordQ.push(i);
		}
	}

	while (!wordQ.empty())
	{
		int tempIndex = wordQ.front();

		if (tempIndex == targetIndex)
			return distance[tempIndex];

		for (int i = 0; i < words.size(); i++)
		{
			if (visited[i])
				continue;

			int difCount = 0;
			for(int j = 0; j < words[i].size(); j++)
			{
				if (words[tempIndex][j] != words[i][j])
				{
					difCount++;
				}
				if (difCount > 1)
					break;
			}

			if (difCount == 1)
			{
				visited[i] = true;
				distance[i] = distance[tempIndex] + 1;
				wordQ.push(i);
			}
		}
		wordQ.pop();
	}


	return answer;
}