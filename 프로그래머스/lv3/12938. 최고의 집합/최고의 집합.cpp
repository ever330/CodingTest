#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
	if (n == 1)
	{
		answer.push_back(s);
	}
	else if (n > 1 && s < n)
	{
		answer.push_back(-1);
	}
	else
	{
		if (s % n == 0)
		{
			for (int i = 0; i < n; i++)
			{
				answer.push_back(s / n);
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i < n - s % n)
				{
					answer.push_back(s / n);
				}
				else
				{
					answer.push_back(s / n + 1);
				}
			}
		}
	}

	return answer;
}