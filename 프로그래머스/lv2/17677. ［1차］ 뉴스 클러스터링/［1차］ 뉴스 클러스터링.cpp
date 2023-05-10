#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	float unionCount = 0;
	float intersection = 0;

	vector<string> arr1;
	vector<string> arr2;

	string nowStr = "";
	for (auto i = 0; i < str1.size() - 1; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			nowStr += str1[i];
			if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
			{
				nowStr += str1[i + 1];
				arr1.push_back(nowStr);
			}
			else if (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
			{
				nowStr += (str1[i + 1] + 32);
				arr1.push_back(nowStr);
			}
		}
		else if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			nowStr += (str1[i] + 32);
			if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
			{
				nowStr += str1[i + 1];
				arr1.push_back(nowStr);
			}
			else if (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
			{
				nowStr += (str1[i + 1] + 32);
				arr1.push_back(nowStr);
			}
		}
		nowStr = "";
	}

	nowStr = "";
	for (auto i = 0; i < str2.size(); i++)
	{
		if (str2[i] >= 'a' && str2[i] <= 'z')
		{
			nowStr += str2[i];
			if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
			{
				nowStr += str2[i + 1];
				arr2.push_back(nowStr);
			}
			else if (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
			{
				nowStr += (str2[i + 1] + 32);
				arr2.push_back(nowStr);
			}
		}
		else if (str2[i] >= 'A' && str2[i] <= 'Z')
		{
			nowStr += (str2[i] + 32);
			if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
			{
				nowStr += str2[i + 1];
				arr2.push_back(nowStr);
			}
			else if (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
			{
				nowStr += (str2[i + 1] + 32);
				arr2.push_back(nowStr);
			}
		}
		nowStr = "";
	}

	intersection = arr1.size() + arr2.size();

	int notSameCount = 0;
	int a = 0;
	int b = 0;

	while (notSameCount < arr1.size() * arr2.size())
	{
		if (arr1[a] == arr2[b])
		{
			arr1.erase(arr1.begin() + a);
			arr2.erase(arr2.begin() + b);
			unionCount++;
			notSameCount = 0;

			if (a >= arr1.size())
			{
				a = 0;
			}
			if (b >= arr2.size())
			{
				b = 0;
			}
		}
		else
		{
			b++;
			if (b >= arr2.size())
			{
				b = 0;
				a++;
				if (a >= arr1.size())
				{
					a = 0;
				}
			}
			notSameCount++;
		}
	}

	answer = (unionCount / (intersection - unionCount)) * 65536;
	if (unionCount == 0 && intersection == 0)
	{
		answer = 65536;
	}

	return answer;
}