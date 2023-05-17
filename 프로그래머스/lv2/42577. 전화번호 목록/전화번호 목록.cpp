#include <string>
#include <vector>
#include <set>

using namespace std;

bool compare(string a, string b)
{
	return a.size() < b.size();
}

bool solution(vector<string> phone_book)
{
	bool answer = true;
	
	set<string> phoneSet;

	for (auto phoneNum : phone_book)
	{
		phoneSet.insert(phoneNum);
	}

	for (auto iter1 = phoneSet.begin(); iter1 != phoneSet.end(); iter1++)
	{
		for (auto iter2 = iter1; iter2 != phoneSet.end(); iter2++)
        {
			if (iter1 != iter2)
			{
				if (iter2->find(*iter1) == 0)
				{
					answer = false;
					break;
				}
				else
					break;
			}
		}
	}

	return answer;
}