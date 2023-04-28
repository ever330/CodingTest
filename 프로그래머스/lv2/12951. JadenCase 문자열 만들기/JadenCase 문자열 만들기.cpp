#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";

	bool isNextUpper = false;

	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}

	for (auto i = 1; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			isNextUpper = true;
		}
		else
		{
			if (isNextUpper)
			{
				if (s[i] >= 'a' && s[i] <= 'z')
				{
					s[i] -= 32;
				}
				isNextUpper = false;
			}
			else
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					s[i] += 32;
				}
			}
		}
	}
	answer = s;

	return answer;
}