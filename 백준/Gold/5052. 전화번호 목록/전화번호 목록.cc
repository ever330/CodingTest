#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Trie
{
    bool isEnd;
    Trie* nextNum[10];

    Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            nextNum[i] = NULL;
        }
        isEnd = false;
    }

    ~Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            if (nextNum[i] != NULL)
            {
                delete nextNum[i];
            }
        }
    }

    bool Insert(const char* nums)
    {
        if (*nums == '\0')
        {
            isEnd = true;
            return true;
        }
        else
        {
            if (isEnd)
            {
                return false;
            }

            if (nextNum[*nums - '0'] == NULL)
            {
                nextNum[*nums - '0'] = new Trie();
            }
            else if (nextNum[*nums - '0'] != 0 && *(nums + 1) == '\0') 
            {
                return false;
            }

            return nextNum[*nums - '0']->Insert(nums + 1);
        }
    }
};

int t = 0;
char numbers[10000][11];

int main()
{
    cin >> t;

    while (t--)
    {
        Trie* node = new Trie();

        int n;
        cin >> n;

        bool res = true;
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];

            if (!res)
            {
                continue;
            }

            res = node->Insert(numbers[i]);
        }

        if (res)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        delete node;
    }

    return 0;
}