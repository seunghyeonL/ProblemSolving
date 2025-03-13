#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while (!deliveries.empty() && deliveries.back() == 0)
    {
        deliveries.pop_back();
    }

    while (!pickups.empty() && pickups.back() == 0)
    {
        pickups.pop_back();
    }
    
    while(!deliveries.empty() || !pickups.empty())
    {
        answer += max(deliveries.size(), pickups.size()) * 2;
        int curD = cap;
        while(!deliveries.empty())
        {
            int& back = deliveries.back();
            if(curD >= back) 
            {
                curD -= back;
                deliveries.pop_back();
            }
            else
            {
                if (curD == 0) break;
                back -= curD;
                curD = 0;
            }
        }
        
        int curP = cap;
        while(!pickups.empty())
        {
            int& back = pickups.back();
            if(curP >= back) 
            {
                curP -= back;
                pickups.pop_back();
            }
            else
            {
                if (curP == 0) break;
                back -= curP;
                curP = 0;
            }
        }
        
    }
    return answer;
}