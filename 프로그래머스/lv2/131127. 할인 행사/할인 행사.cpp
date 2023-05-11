#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<int> count(number.size());
	vector<string> product;

	for (auto i = 0; i < discount.size(); i++)
	{
		product.push_back(discount[i]);
		string popProduct = "";
		if (product.size() > 10)
		{
			popProduct = product.front();
			product.erase(product.begin());
			if (find(want.begin(), want.end(), popProduct) != want.end())
			{
				count[find(want.begin(), want.end(), popProduct) - want.begin()]--;
			}
		}
		for (auto j = 0; j < want.size(); j++)
		{
			if (want[j] == product.back())
			{
				count[j]++;
				break;
			}
		}

		int sum = 0;
		for (auto k = 0; k < count.size(); k++)
		{
			if (count[k] == number[k])
			{
				sum += count[k];
			}
			if (sum >= 10)
			{
				answer++;
			}
		}
	}
    return answer;
}