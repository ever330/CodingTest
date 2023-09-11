#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge_truck;
    int weightSum = 0;
    int truckIndex = 0;
    
    for (int i = 0; i < bridge_length; i++)
    {
        bridge_truck.push(0);
    }
    
    while (truckIndex < truck_weights.size())
    {
        answer++;
        weightSum -= bridge_truck.front();
        bridge_truck.pop();
        if (weightSum + truck_weights[truckIndex] <= weight)
        {
            bridge_truck.push(truck_weights[truckIndex]);
            weightSum += truck_weights[truckIndex];
            truckIndex++;
        }
        else
        {
            bridge_truck.push(0);
        }
    }

    answer += bridge_length;
    
    return answer;
}