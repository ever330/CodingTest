#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (auto i = left; i <= right; i++)
	{
		int a = i / n;
		int b = i % n;
		if (a > b)
		{
			answer.push_back(a + 1);
		}
		else
		{
			answer.push_back(b + 1);
		}
	}
    
    return answer;
}