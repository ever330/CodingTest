#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool CheckPrime(long long n)
{
	if (n == 1)
    {
		return false;
	}
	else if (n == 2)
	{
		return true;
	}
	else
	{
		for (auto i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}

int solution(int n, int k) {
    int answer = -1;
	answer = 0;
	string nChange;
	vector<int> zeroIndex;

	while (n >= k)
	{
		nChange = to_string((n % k)) + nChange;
		n /= k;
		if (n < k)
		{
			nChange = to_string(n) + nChange;
		}
	}

	int index = nChange.find("0");
	while (index != string::npos)
	{
		zeroIndex.push_back(index);
		if (index < nChange.size())
		{
			index = nChange.find("0", index + 1);
		}
	}
	if (!zeroIndex.empty())
	{
		if (zeroIndex[0] != 0)
		{
			int nowNum = stoi(nChange.substr(0, zeroIndex[0]));
			if (CheckPrime(nowNum))
			{
				answer++;
			}
		}
		if (zeroIndex.back() < nChange.size() - 1)
		{
			int nowNum = stoi(nChange.substr(zeroIndex.back()));
			if (CheckPrime(nowNum))
			{
				answer++;
			}
		}

		for (auto i = 0; i < zeroIndex.size() - 1; i++)
		{
			if (zeroIndex[i + 1] - zeroIndex[i] > 1)
			{
				int nowNum = stoi(nChange.substr(zeroIndex[i], zeroIndex[i + 1] - zeroIndex[i]));
				if (CheckPrime(nowNum))
				{
					answer++;
				}
			}
		}
	}
	else
	{
		double checkNum = stol(nChange);
		if (CheckPrime(checkNum))
		{
			answer++;
		}
	}

    return answer;
}