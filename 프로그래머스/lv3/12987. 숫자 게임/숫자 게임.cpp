#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int bIndex = 0;
	bool isAllSmall = false;

	for (auto i = 0; i < A.size(); i++)
	{
		for (auto j = bIndex; j < B.size(); j++)
		{
			if (A[i] < B[j])
			{
				bIndex = j + 1;
				answer++;
				break;
			}
			if (j == B.size() - 1)
			{
				isAllSmall = true;
			}
		}
		if (isAllSmall)
		{
			break;
		}
	}

	return answer;
}