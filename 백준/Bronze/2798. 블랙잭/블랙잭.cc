//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    vector<int> sumVec;
    for (int i = 0; i < n - 2; i++)
    {
        if (vec[i] >= m)
            continue;

        for (int j = i + 1; j < n - 1; j++)
        {
            if (vec[i] + vec[j] >= m)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (vec[i] + vec[j] + vec[k] > m)
                    continue;

                sumVec.push_back(vec[i] + vec[j] + vec[k]);
            }
        }
    }

    sort(sumVec.begin(), sumVec.end(), greater<int>());

    for (int i = 0; i < sumVec.size(); i++)
    {
        if (sumVec[i] <= m)
        {
            cout << sumVec[i];
            break;
        }
    }

    return 0;
}