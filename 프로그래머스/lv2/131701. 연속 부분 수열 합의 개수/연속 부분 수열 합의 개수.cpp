#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

	vector<bool> isExit(1000001);

	int maxNum = 0;

	for (auto i = 0; i < elements.size(); i++)
	{
		int sum = 0;
		for (auto j = 0; j < elements.size(); j++)
		{
			if (i + j >= elements.size())
			{
				sum += elements[i + j - elements.size()];
			}
			else
			{
				sum += elements[i + j];
			}
			isExit[sum] = true;
			if (maxNum < sum)
				maxNum = sum;
		}
	}

	for (auto i = 0; i <= maxNum; i++)
	{
		if (isExit[i])
			answer++;
	}
    
    return answer;
}