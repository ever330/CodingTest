#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

	for (auto i = 0; i < arr1.size(); i++)
	{
		vector<int> nowVec;
		for (auto j = 0; j < arr2[0].size(); j++)
		{
			int num = 0;
			for (auto k = 0; k < arr2.size(); k++)
			{
				num += arr1[i][k] * arr2[k][j];
			}
			nowVec.emplace_back(num);
		}
		answer.emplace_back(nowVec);
	}
    
    return answer;
}