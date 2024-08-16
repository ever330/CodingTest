#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int t = 0;

int main()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string func = "";
        cin >> func;

        int delCnt = 0;
        for (int i = 0; i < func.length(); i++)
        {
            if (func[i] == 'D')
            {
                delCnt++;
            }
        }

        int count = 0;
        cin >> count;

        string nums = "";
        cin >> nums;

        if (delCnt > count)
        {
            cout << "error" << endl;
        }
        else
        {
            deque<int> dq;
            string str = "";
            for (int i = 1; i < nums.length(); i++)
            {
                if ((nums[i] == ',' || nums[i] == ']') && str != "")
                {
                    dq.push_back(stoi(str));
                    str = "";
                }
                else
                {
                    str += nums[i];
                }
            }

            bool isReversed = false;
            for (int i = 0; i < func.length(); i++)
            {
                if (func[i] == 'R')
                {
                    isReversed = !isReversed;
                }
                else
                {
                    if (isReversed)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }

            cout << '[';
            if (isReversed)
            {
                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    cout << dq[i];
                    if (i > 0)
                    {
                        cout << ',';
                    }
                }
            }
            else
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    cout << dq[i];
                    if (i < dq.size() - 1)
                    {
                        cout << ',';
                    }
                }
            }
            cout << ']' << endl;
        }
    }

    return 0;
}