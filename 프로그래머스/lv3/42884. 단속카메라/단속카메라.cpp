#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), Compare);

	vector<int> nowRoute = routes[0];
	answer++;

	for (int i = 1; i < routes.size(); i++)
	{
		if (nowRoute[1] < routes[i][0])
		{
			nowRoute = routes[i];
			answer++;
		}
	}
    return answer;
}