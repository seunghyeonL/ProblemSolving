#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int loadOnBridge = 0;
    queue<int> bridge;
    for (int _ = 0; _ < bridge_length; ++_)
    {
        bridge.push(0);
    }

    int time = 0;
    int truckIdx = 0;

    while (!bridge.empty())
    {
        int curTruckOut = bridge.front();
        int curTruckIn = truck_weights[truckIdx];
        loadOnBridge -= curTruckOut;
        bridge.pop();

        if (truckIdx < truck_weights.size())
        {
            if (loadOnBridge + curTruckIn <= weight)
            {
                loadOnBridge += curTruckIn;
                bridge.push(curTruckIn);
                ++truckIdx;
            }
            else
            {
                bridge.push(0);
            }
        }

        // cout << "outTruck: " << curTruckOut << '\n';
        // cout << "load Bridge: " << loadOnBridge << '\n';
        time++;
    }

    return time;
}