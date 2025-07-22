#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> routes) {
    using P = pair<int, int>;
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](auto a, auto b){ return a[1] < b[1]; });
    queue<P> q;
    
    for (auto route : routes)
    {
        q.emplace(route[0], route[1]);
    }
    
    
    while (!q.empty())
    {
        auto [enter, exit] = q.front();
        q.pop();
        answer++;
        
        while (!q.empty())
        {
            auto [enter2, exit2] = q.front();
            if (enter2 <= exit)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
    }
    
    
    return answer;
}