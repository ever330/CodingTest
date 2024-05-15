#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<string> book1, vector<string> book2)
{
    int book1InHour = stoi(book1[0].substr(0, 2));
    int book1InMinite = stoi(book1[0].substr(3, 2));
    int book2InHour = stoi(book2[0].substr(0, 2));
    int book2InMinite = stoi(book2[0].substr(3, 2));
    
    return (book1InHour * 60 + book1InMinite) < (book2InHour * 60 + book2InMinite);
}


int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> outTime;
        
    sort(book_time.begin(), book_time.end(), compare);
    
    for (int i = 0; i < book_time.size(); i++)
    {
        int curInHour = stoi(book_time[i][0].substr(0, 2));
        int curInMinite = stoi(book_time[i][0].substr(3, 2));
        int totalInMinite = curInHour * 60 + curInMinite;

        int curOutHour = stoi(book_time[i][1].substr(0, 2));
        int curOutMinite = stoi(book_time[i][1].substr(3, 2));
        int totalOutMinite = curOutHour * 60 + curOutMinite;

        if (i == 0)
        {
            outTime.push_back(totalOutMinite);
        }
        else
        {
            bool cantUse = false;
            for (int j = 0; j < outTime.size(); j++)
            {
                if (outTime[j] + 10 <= totalInMinite)
                {
                    outTime[j] = totalOutMinite;
                    cantUse = true;
                    break;
                }
            }
            if (!cantUse)
            {
                outTime.push_back(totalOutMinite);
            }
        }
    }
    
    answer = outTime.size();
        
    return answer;
}