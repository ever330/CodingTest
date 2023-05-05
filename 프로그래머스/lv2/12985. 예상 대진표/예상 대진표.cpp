#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

	int num = n;

	while (num > 1)
	{
		if ((n / 2 > a && n / 2 < b) || (n / 2 < a && n / 2 > b))
		{
			num /= 2;
			answer++;
		}
		else
		{
			n /= 2;
			num = n;
		}
	}

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}