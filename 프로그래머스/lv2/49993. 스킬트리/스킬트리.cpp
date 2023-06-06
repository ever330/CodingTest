#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

	if (skill.size() == 1)
	{
		answer = skill_trees.size();
	}
	else
	{
		for (string skill_tree : skill_trees)
		{
			int count = 0;
			bool isSuccesss = true;
			for (auto i = 0; i < skill_tree.length(); i++)
			{
				int index = skill.find(skill_tree[i]);
				if (index != string::npos && count == index)
				{
					count++;
				}
				else if (index != string::npos && count != index)
				{
					isSuccesss = false;
					break;
				}
			}
			if (isSuccesss)
			{
				answer++;
			}
		}
	}
    
    return answer;
}