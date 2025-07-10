#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int time = -1;
    queue<int> servers;
    
    while (time < 24)
    {
        time++;
        
        // 서버 반납
        while (!servers.empty() && servers.front() == time)
        {
            servers.pop();
        }
        
        // 필요시 서버 증설
        int curServerSize = servers.size();
        int serverNeeds = players[time] / m;
        int additionalServerNeeds = max(0, serverNeeds - curServerSize);
        
        answer += additionalServerNeeds;
        
        for(int i = 0 ; i < additionalServerNeeds ; i++)
        {
            servers.push(time + k);
        }
    }
    
    
    return answer;
}