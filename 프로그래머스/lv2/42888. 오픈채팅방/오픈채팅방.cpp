#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
	map<string, string> user;
	vector<vector<string>> analyzedRecord;

	for (auto i = 0; i < record.size(); i++)
	{
		istringstream iss(record[i]);
		
		vector<string> newRecord(4);
		int index = 0;
		while (getline(iss, newRecord[index], ' '))
		{
			index++;
		}
		if (newRecord[0] == "Enter")
		{
			if (user.find(newRecord[1]) != user.end())
			{
				user[newRecord[1]] = newRecord[2];
			}
			else if (user.find(newRecord[1]) == user.end())
			{
				user.insert({newRecord[1], newRecord[2]});
			}
			vector<string> re = { newRecord[0], newRecord[1] };
			analyzedRecord.emplace_back(re);
		}
		else if (newRecord[0] == "Change")
		{
			if (user.find(newRecord[1]) != user.end())
			{
				user[newRecord[1]] = newRecord[2];
			}
		}
		else
		{
			vector<string> re = { newRecord[0], newRecord[1] };
			analyzedRecord.emplace_back(re);
		}
	}

	for (auto i = 0; i < analyzedRecord.size(); i++)
	{
		string userName = user[analyzedRecord[i][1]];
		string state = analyzedRecord[i][0];

		if (state == "Enter")
		{
			answer.emplace_back(userName + "님이 들어왔습니다.");
		}
		else
		{
			answer.emplace_back(userName + "님이 나갔습니다.");
		}
	}
    return answer;
}