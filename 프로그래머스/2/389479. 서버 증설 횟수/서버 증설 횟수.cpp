#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int time = -1;
    deque<int> servers;
    
    while (time < 24)
    {
        time++;
        
        // 서버 반납
        for(int& timeRemain : servers)
        {
            timeRemain--;
        }
        
        while (!servers.empty() && servers[0] == 0)
        {
            servers.pop_front();
        }
        
        // 필요시 서버 증설
        int curServerSize = servers.size();
        int serverNeeds = players[time] / m;
        int additionalServerNeeds = max(0, serverNeeds - curServerSize);
        
        answer += additionalServerNeeds;
        
        for(int i = 0 ; i < additionalServerNeeds ; i++)
        {
            servers.push_back(k);
        }
    }
    
    
    return answer;
}