#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
   
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	if (pq.top() >= K)
	{
		return answer;
	}

	while (!pq.empty())
	{
		int num1 = pq.top();
		pq.pop();
		if (!pq.empty())
		{
			int num2 = pq.top();
			pq.pop();
			int sum = num1 + num2 * 2;
			pq.push(sum);
			answer++;
		}
		if (pq.top() >= K)
		{
			return answer;
		}
	}

	return -1;
}