#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
	list<string> cache;

	for (auto i = 0; i < cities.size(); i++) 
	{
		if (cacheSize == 0)
		{
			answer += 5;
		}
		else
		{
			for (auto j = 0; j < cities[i].size(); j++)
			{
				if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
				{
					cities[i][j] += 32;
				}
			}
			auto iter = find(cache.begin(), cache.end(), cities[i]);
			if (cache.empty())
			{
				cache.emplace_front(cities[i]);
				answer += 5;
			}
			else if (iter == cache.end())
			{
				if (cache.size() >= cacheSize)
				{
					cache.pop_back();
					cache.emplace_front(cities[i]);
				}
				else
				{
					cache.emplace_front(cities[i]);
				}
				answer += 5;
			}
			else
			{
				cache.erase(iter);
				cache.emplace_front(cities[i]);
				answer += 1;
			}
		}
	}
    
    return answer;
}