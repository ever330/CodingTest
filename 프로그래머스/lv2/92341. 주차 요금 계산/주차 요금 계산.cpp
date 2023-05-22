#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) 
{
	vector<int> answer;

	vector<vector<int>> sortRecord;

	for (auto i = 0; i < records.size(); i++)
	{
		vector<int> newRecord;
		int time = 0;
		int carNum = stoi(records[i].substr(6, 4));
		string str = records[i].substr(11);
		if (str == "IN")
		{
			time = -(stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2)));
		}
		else
		{
			time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
		}
		newRecord.emplace_back(carNum);
		newRecord.emplace_back(time);

		if (sortRecord.empty())
		{
			sortRecord.emplace_back(newRecord);
		}
		else
		{
			for (auto j = 0; j < sortRecord.size(); j++)
			{
				if (sortRecord[j][0] == newRecord[0])
				{
					sortRecord[j][1] += newRecord[1];
					break;
				}
				else if (sortRecord[j][0] > newRecord[0])
				{
					sortRecord.insert(sortRecord.begin() + j, newRecord);
					break;
				}
				
				if (j == sortRecord.size() - 1)
				{
					sortRecord.emplace_back(newRecord);
					break;
				}
			}
		}
	}

	for (auto i = 0; i < sortRecord.size(); i++)
	{
		int money = 0;
		if (sortRecord[i][1] <= 0)
		{
			sortRecord[i][1] += 23 * 60 + 59;
		}

		if (sortRecord[i][1] <= fees[0])
		{
			money = fees[1];
		}
		else
		{
			int time;
			if ((sortRecord[i][1] - fees[0]) % fees[2] != 0)
			{
				time = (sortRecord[i][1] - fees[0]) / fees[2] + 1;
			}
			else
			{
				time = (sortRecord[i][1] - fees[0]) / fees[2];
			}
			money = fees[1] + time * fees[3];
		}
		answer.emplace_back(money);
	}

	return answer;
}