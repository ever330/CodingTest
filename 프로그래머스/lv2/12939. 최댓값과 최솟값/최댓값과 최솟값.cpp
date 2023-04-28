#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

	istringstream ss(s);
	string strBuf;
	vector<string> v;

	int minNum = 0;
	int maxNum = 0;

	v.clear();
	while(getline(ss, strBuf, ' '))
	{
		v.push_back(strBuf);
	}

	minNum = stoi(v[0]);
	maxNum = stoi(v[0]);

	for (auto str : v)
	{
		if (stoi(str) > maxNum)
		{
			maxNum = stoi(str);
		}
		if (stoi(str) < minNum)
		{
			minNum = stoi(str);
		}
	}
	answer = to_string(minNum) + " " + to_string(maxNum);

	return answer;
}