#include <string>
#include <vector>

using namespace std;

string NumberChange(int base, int num)
{
	string changeNum;

	if (num == 0)
	{
		changeNum = "0";
		return changeNum;
	}

	while (num > 1)
	{
		if (base > 10)
		{
			if (num % base == 10)
			{
				changeNum.insert(0, "A");
			}
			else if (num % base == 11)
			{
				changeNum.insert(0, "B");
			}
			else if (num % base == 12)
			{
				changeNum.insert(0, "C");
			}
			else if (num % base == 13)
			{
				changeNum.insert(0, "D");
			}
			else if (num % base == 14)
			{
				changeNum.insert(0, "E");
			}
			else if (num % base == 15)
			{
				changeNum.insert(0, "F");
			}
			else
			{
				changeNum.insert(0, to_string(num % base));
			}
		}
		else
		{
			changeNum.insert(0, to_string(num % base));
		}
		num /= base;
	}

	if (num != 0)
	{
		changeNum.insert(0, to_string(num));
	}

	return changeNum;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int nowNum = 0;
	int nowCount = 0;

	while (answer.size() < t)
	{
		string changeNum = NumberChange(n, nowNum);
		for (auto i = nowCount; i < nowCount + changeNum.size(); i++)
		{
			if (i % m == p - 1)
			{
				answer += changeNum[i - nowCount];
			}
			if (answer.size() >= t)
			{
				break;
			}
		}
		nowCount += changeNum.size();
		nowNum++;
	}
    
    return answer;
}