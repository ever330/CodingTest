#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
	vector<string> dictionary;
	dictionary.emplace_back("0");
	dictionary.emplace_back("A");
	dictionary.emplace_back("B");
	dictionary.emplace_back("C");
	dictionary.emplace_back("D");
	dictionary.emplace_back("E");
	dictionary.emplace_back("F");
	dictionary.emplace_back("G");
	dictionary.emplace_back("H");
	dictionary.emplace_back("I");
	dictionary.emplace_back("J");
	dictionary.emplace_back("K");
	dictionary.emplace_back("L");
	dictionary.emplace_back("M");
	dictionary.emplace_back("N");
	dictionary.emplace_back("O");
	dictionary.emplace_back("P");
	dictionary.emplace_back("Q");
	dictionary.emplace_back("R");
	dictionary.emplace_back("S");
	dictionary.emplace_back("T");
	dictionary.emplace_back("U");
	dictionary.emplace_back("V");
	dictionary.emplace_back("W");
	dictionary.emplace_back("X");
	dictionary.emplace_back("Y");
	dictionary.emplace_back("Z");

	string findStr;
	for (auto i = 0; i < msg.size(); i++)
	{
		findStr += msg[i];
		if (find(dictionary.begin(), dictionary.end(), findStr + msg[i + 1]) == dictionary.end())
		{
			answer.emplace_back(find(dictionary.begin(), dictionary.end(), findStr) - dictionary.begin());
			dictionary.emplace_back(findStr + msg[i + 1]);
			findStr = "";
		}
	}
    return answer;
}