#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int sum = 0;
    int startIndex = 0;
    queue<int> subSeq;
    
    for (int i = 0; i < sequence.size(); i++)
    {
        if (sequence[i] > k)
            break;
        else if (sequence[i] == k)
        {
            if (answer.empty())
            {
                answer.push_back(i);
                answer.push_back(i);
            }
            else
            {
                answer[0] = i;
                answer[1] = i;
            }
            break;
        }
        
        if (sum + sequence[i] < k)
        {
            sum += sequence[i];
            subSeq.push(sequence[i]);
        }
        else if (sum + sequence[i] == k)
        {
            sum += sequence[i];
            subSeq.push(sequence[i]);
            if (answer.empty())
            {
                answer.push_back(startIndex);
                answer.push_back(startIndex + subSeq.size() - 1);
            }
            else
            {
                int prevLength = answer[1] - answer[0];
                int nowLength = subSeq.size() - 1;
                if (nowLength < prevLength)
                {
                    answer[0] = startIndex;
                    answer[1] = startIndex +  subSeq.size() - 1;
                }
            }
        }
        else
        {
            while (sum + sequence[i] > k)
            {
                sum -= subSeq.front();
                subSeq.pop();
                startIndex++;
                
                if (sum + sequence[i] < k)
                {
                    sum += sequence[i];
                    subSeq.push(sequence[i]);
                    break;
                }
                else if (sum + sequence[i] == k)
                {
                    sum += sequence[i];
                    subSeq.push(sequence[i]);
                    if (answer.empty())
                    {
                        answer.push_back(startIndex);
                        answer.push_back(startIndex + subSeq.size() - 1);
                    }
                    else
                    {
                        int prevLength = answer[1] - answer[0];
                        int nowLength = subSeq.size() - 1;
                        if (nowLength < prevLength)
                        {
                            answer[0] = startIndex;
                            answer[1] = startIndex +  subSeq.size() - 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    
    return answer;
}