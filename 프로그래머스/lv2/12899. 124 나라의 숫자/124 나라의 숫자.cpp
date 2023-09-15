#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (n > 0)
    {
        if (n % 3 == 1)
        {
            answer.insert(0, "1");
        }
        else if (n % 3 == 2)
        {
            answer.insert(0, "2");
        }
        else if (n % 3 == 0)
        {
            answer.insert(0, "4");
            n--;
        }
        n /= 3;
    }
    
    return answer;
}