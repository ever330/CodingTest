#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Trie
{
    bool isEnd;
    Trie* nextNode[26];
    int nextCount;
    
    Trie() : isEnd(false), nextCount(0)
    {
        for (int i = 0; i < 26; i++)
        {
            nextNode[i] = NULL;
        }
    }
    
    void Insert(char* str)
    {
        if (*str == NULL)
        {
            isEnd = true;
            return;
        }
        
        int cur = *str - 'a';
        if (nextNode[cur] == NULL)
            nextNode[cur] = new Trie();
        
        nextNode[cur]->nextCount++;
        nextNode[cur]->Insert(str + 1);
    }
    
    int Find(char* str)
    {
        if (*str == NULL)
        {
            return nextCount;
        }
        
        int cur = *str - 'a';
        if (nextNode[cur] == NULL)
            return 0;
        
        return nextNode[cur]->Find(str + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    unordered_map<int, Trie*> rootMap;
    unordered_map<int, Trie*> reverseRootMap;
    
    int wordLengthCnt[10001] = { 0, };
    
    for (auto word : words)
    {
        wordLengthCnt[word.length()]++;
        if (rootMap.find(word.length()) == rootMap.end())
        {
            rootMap.insert({word.length(), new Trie()});
        }
        rootMap[word.length()]->Insert(const_cast<char*>(word.c_str()));
        
        reverse(word.begin(), word.end());
        if (reverseRootMap.find(word.length()) == reverseRootMap.end())
        {
            reverseRootMap.insert({word.length(), new Trie()});
        }
        reverseRootMap[word.length()]->Insert(const_cast<char*>(word.c_str()));
    }
    
	for (auto query : queries)
	{
		int cnt = 0;
		int qCnt = count(query.begin(), query.end(), '?');

		if (wordLengthCnt[query.length()] == 0 || qCnt == query.length())
		{
			cnt = wordLengthCnt[query.length()];
			answer.push_back(cnt);
			continue;
		}

		string tempSplitStr = "";
		if (query[0] == '?')
		{
			tempSplitStr = query.substr(qCnt);
            reverse(tempSplitStr.begin(), tempSplitStr.end());
			cnt = reverseRootMap[query.length()]->Find(const_cast<char*>(tempSplitStr.c_str()));
		}
		else
		{
			tempSplitStr = query.substr(0, query.length() - qCnt);
			cnt = rootMap[query.length()]->Find(const_cast<char*>(tempSplitStr.c_str()));
		}

		answer.push_back(cnt);
	}
    
    return answer;
}