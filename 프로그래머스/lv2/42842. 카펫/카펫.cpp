#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<int> inside = { 0, 0 };

	int sum = brown + yellow;

	if (yellow <= 3)
	{
		answer.push_back(yellow + 2);
		answer.push_back(1 + 2);
	}
	else
	{
		for (auto i = yellow / 2; i > 0; i--)
		{
			int x = i;
			int y = yellow / i;
			if (yellow % i == 0 && (x + 2) * (y + 2) == sum)
			{
				answer.push_back(x + 2);
				answer.push_back(y + 2);
				break;
			}
		}
	}

	return answer;
}