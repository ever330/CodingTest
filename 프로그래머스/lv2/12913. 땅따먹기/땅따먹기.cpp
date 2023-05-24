#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int> > land)
{
    int answer = 0;


	int landCount = land.size();

	for (auto i = 1; i < landCount; i++)
	{
		land[i][0] += max(max(land[i - 1][1], land[i - 1][2]), land[i - 1][3]);
		land[i][1] += max(max(land[i - 1][0], land[i - 1][2]), land[i - 1][3]);
		land[i][2] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][3]);
		land[i][3] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][2]);
	}

	answer = *max_element(land[landCount - 1].begin(), land[landCount - 1].end());

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}