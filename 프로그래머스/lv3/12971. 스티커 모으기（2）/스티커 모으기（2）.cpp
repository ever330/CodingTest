#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;

    if (sticker.size() == 1)
    {
        return sticker[0];
    }
    
	vector<int> dp0;
	vector<int> dp1;

	for (int i = 0; i < sticker.size() - 1; i++)
	{
		dp0.push_back(sticker[i]);
	}

	for (int i = 1; i < sticker.size(); i++)
	{
		dp1.push_back(sticker[i]);
	}

	for (int i = 1; i < dp0.size(); i++)
	{
		if (i == 1)
		{
			dp0[i] = max(dp0[i], dp0[i - 1]);
			dp1[i] = max(dp1[i], dp1[i - 1]);
		}
		else
		{
			dp0[i] = max(dp0[i] + dp0[i - 2], dp0[i - 1]);
			dp1[i] = max(dp1[i] + dp1[i - 2], dp1[i - 1]);
		}
	}

	answer = max(dp0.back(), dp1.back());
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}