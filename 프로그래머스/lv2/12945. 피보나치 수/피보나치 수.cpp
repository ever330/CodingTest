#include <string>
#include <vector>

using namespace std;

int Fibonacci(int n)
{
    int fiboCount = 2;
    vector<int> fibo(100001);

    fibo[0] = 0;
    fibo[1] = 1;
    
    while (fiboCount <= n)
    {
        fibo[fiboCount] = fibo[fiboCount - 2] + fibo[fiboCount - 1];
        fibo[fiboCount] %= 1234567;
        fiboCount++;
    }
    
    return fibo[n];
}

int solution(int n) {
    int answer = 0;

    answer = Fibonacci(n);

    return answer;
}