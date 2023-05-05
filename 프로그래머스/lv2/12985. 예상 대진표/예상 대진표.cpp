#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

	int num = 0;

	while (true)
	{
		if ((n / 2 >= a && n / 2 < b) || (n / 2 < a && n / 2 >= b))
		{
			num = n;
			break;
		}
		else if (n / 2 < a && n / 2 < b) 
		{
			n = n / 2;
			a -= n;
			b -= n;
		}
		else if (n / 2 >= a && n / 2 >= b)
		{
			n /= 2;
		}
	}

	while (num > 1)
	{
		num /= 2;
		answer++;
	}
    
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}