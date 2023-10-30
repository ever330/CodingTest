#include <string>
#include <vector>

using namespace std;

struct Trie
{
    bool isEnd;
    Trie* next[26];
    int count;

    Trie() : isEnd(false), count(0)
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
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
        if (next[cur] == NULL)
        {
            next[cur] = new Trie();
        }
        isEnd = false;
        next[cur]->count++;
        next[cur]->Insert(str + 1);
    }

    bool Find(char* str)
    {
        int cur = *str - 'a';
        if (*str == NULL)
        {
            if (count == 1) 
                return true;
            return false;
        }
        if (next[cur] == NULL)
            return false;
        return next[cur]->Find(str + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;

    Trie* root = new Trie();

    for (auto& word : words)
    {
        root->Insert(const_cast<char*>(word.c_str()));
    }

    for (auto& word : words)
    {
        int count = 0;

        for (int i = 1; i <= word.length(); i++)
        {
            count++;
            string tempStr = word.substr(0, i);
            char* tempChar = const_cast<char*>(tempStr.c_str());
            if (root->Find(tempChar))
                break;
        }
        answer += count;
    }

    return answer;
}