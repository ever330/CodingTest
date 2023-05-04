#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int solution(vector<int> people, int limit) {
   int answer = 0;

	sort(people.begin(), people.end(), compare);
	vector<bool> savePeople(people.size());
	int sum = 0;

	for (auto i = 0; i < people.size(); i++)
	{
		sum = people[i];
			for (auto j = people.size() - 1; j > i; j--)
			{
				if (sum + people[j] > limit)
				{
					break;
				}
				if (sum + people[j] <= limit)
				{
					sum += people[j];
					people.erase(people.begin() + j);
				}
			}
			answer++;
	}

	return answer;
}