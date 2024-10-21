#include <string>
#include <vector>
#include <iostream>

using namespace std;

string StringChange(string m)
{
    string str = "";
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i + 1] == '#')
        {
            str.append(1, m[i] + 32);
            i++;
        }
        else
        {
            str.append(1, m[i]);
        }
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    string str = "";
    char prevC = m[0];
    
    if (m.length() == 1)
        str.append(1, m[0]);
    else
        str = StringChange(m);
    
    int prevMaxTime = 0;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector<string> infos;
        size_t pos = 0;
        string token;
        string delimiter = ",";
        
        while ((pos = musicinfos[i].find(delimiter)) != string::npos) 
        {
            token = musicinfos[i].substr(0, pos);
            infos.push_back(token);
            musicinfos[i].erase(0, pos + delimiter.length());
        }
        infos.push_back(musicinfos[i]);
        
        string endH = infos[1].substr(0, 2);
        string endM = infos[1].substr(3, 2);
        string startH = infos[0].substr(0, 2);
        string startM = infos[0].substr(3, 2);
        
        int totalTime = (stoi(endH) - stoi(startH)) * 60 + stoi(endM) - stoi(startM);
        string sheet = "";
        infos[3] = StringChange(infos[3]);
        int quo = totalTime / infos[3].length();
        int rem = totalTime % infos[3].length();
        for (int j = 0 ; j < quo; j++)
        {
            sheet += infos[3];
        }
        for (int j = 0; j < rem; j++)
        {
            sheet.append(1, infos[3][j]);
        }
        
        if (sheet.find(str) != string::npos) 
        {
            if (prevMaxTime < totalTime)
            {
                prevMaxTime = totalTime;
                answer = infos[2];
            }
        } 
    }
    
    return answer;
}