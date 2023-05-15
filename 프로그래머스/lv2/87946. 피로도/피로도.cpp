#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
	if (a[0] == b[0])
	{
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	answer = 0;
	sort(dungeons.begin(), dungeons.end(), compare);

	do
	{
		int sum = 0;
		int tired = k;
		for (auto i = 0; i < dungeons.size();i++)
		{
			if (tired >= dungeons[i][0])
			{
				tired -= dungeons[i][1];
				sum++;
			}
		}
		answer = max(answer, sum);
	}while (next_permutation(dungeons.begin(), dungeons.end()));

	return answer;
}