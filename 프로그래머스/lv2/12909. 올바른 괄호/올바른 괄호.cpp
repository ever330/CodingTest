#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
	int count = 0;

	if (s[0] == ')')
	{
		answer = false;
	}
	else
	{
		count++;
		for (auto i = 1; i < s.size(); i++)
		{
			if (s[i] == ')')
			{
				count--;
				if (count < 0)
				{
					answer = false;
					break;
				}
			}
			else if (s[i] == '(')
			{
				count++;
			}
		}
		if (count == 0)
		{
			answer = true;
		}
		else
		{
			answer = false;
		}
	}

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}