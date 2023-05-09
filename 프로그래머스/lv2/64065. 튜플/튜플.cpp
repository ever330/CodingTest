#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> numArr(501);

	string newString = s.substr(1, s.size() - 2);

	vector<int> nowNums;
	string numStr;
	int nowCount = 1;
	for (auto i = 0; i < newString.size(); i++)
	{
		if (newString[i] == '{')
		{
			numStr = "";
			nowCount = 1;
			nowNums.clear();
		}
		else if (newString[i] == '}')
		{
			nowNums.push_back(stoi(numStr));
			numStr = "";
			for (auto j = 0; j < nowNums.size(); j++)
			{
				numArr[nowCount].push_back(nowNums[j]);
			}
		}
		else if (newString[i] == ',')
		{
			if (numStr != "")
			{
				nowNums.push_back(stoi(numStr));
				nowCount++;
			}
			numStr = "";
		}
		else
		{
			numStr += newString[i];
		}
	}

	for (auto nums : numArr)
	{
		for (auto i = 0; i < nums.size(); i++)
		{
			if (find(answer.begin(), answer.end(), nums[i]) == answer.end())
			{
				answer.push_back(nums[i]);
			}
		}
	}
    return answer;
}