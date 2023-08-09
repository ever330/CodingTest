#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b)
{
	return a.second > b.second;
}

bool compare2(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> genreSum;
	map<string, vector<pair<int, int>>> genreList;

	for (int i = 0 ; i < genres.size(); i++)
	{
		if (genreSum.find(genres[i]) != genreSum.end())
		{
			genreSum[genres[i]] += plays[i];
			genreList[genres[i]].push_back({ plays[i], i });
		}
		else
		{
			genreSum.insert({ genres[i], plays[i] });
			vector<pair<int, int>> newGenre;
			newGenre.push_back({ plays[i], i });
			genreList.insert( { genres[i], newGenre });
		}
	}

	vector<pair<string, int>> genreVec(genreSum.begin(), genreSum.end());

	sort(genreVec.begin(), genreVec.end(), compare);

	for (int i = 0; i < genreVec.size(); i++)
	{
		string nowGenre = genreVec[i].first;
		sort(genreList[nowGenre].begin(), genreList[nowGenre].end(), compare2);

		if (genreList[nowGenre].size() == 1)
		{
			answer.push_back(genreList[nowGenre].begin()->second);
		}
		else
		{
			answer.push_back(genreList[nowGenre].begin()->second);
			answer.push_back((++genreList[nowGenre].begin())->second);
		}
	}

	return answer;
}