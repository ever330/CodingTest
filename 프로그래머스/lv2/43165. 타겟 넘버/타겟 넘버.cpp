#include <string>
#include <vector>

using namespace std;

int answer = 0;

void Calculate(vector<int> numbers, int findIndex, int sum, int target)
{
	if (findIndex == numbers.size() - 1)
	{
		if (sum == target)
		{
			answer++;
		}
	}
	else
	{
		findIndex++;
		Calculate(numbers, findIndex, sum + numbers[findIndex], target);
		Calculate(numbers, findIndex, sum - numbers[findIndex], target);
	}
}

int solution(vector<int> numbers, int target) 
{
	Calculate(numbers, 0, numbers[0], target); 
	Calculate(numbers, 0, -numbers[0], target);


	return answer;
}
