#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

	int coverRange = w * 2 + 1;
	int prevIndex = 1;

	for (auto station : stations)
	{
		int startIndex = station - w;
		int endIndex = station + w;

		if (startIndex - prevIndex >= 1)
		{
			answer += (startIndex - prevIndex) / coverRange;
			if ((startIndex - prevIndex) % coverRange != 0)
			{
				answer++;
			}
		}
		prevIndex = endIndex + 1;
	}
    
	if (prevIndex <= n)
	{
		answer += (n - prevIndex) / coverRange + 1;
	}
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}