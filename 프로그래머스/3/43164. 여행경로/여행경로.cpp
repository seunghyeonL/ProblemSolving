#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> history{"ICN"};
    int size = tickets.size();
    
//     vector<pair<string, string>> ptickets;
//     ptickets.reserve(size);
    
//     for (const auto& ticket : tickets)
//     {
//         string u = ticket[0];
//         string v = ticket[1];
        
//         ptickets.emplace_back(u, v);
//     }
    
    sort(tickets.begin(), tickets.end(), [](const auto& a, const auto& b){ 
        return a[1] < b[1];
    });
    
    // 출발 공항, 티켓 idx
    unordered_map<string, vector<int>> adj;
    
    for (int i = 0 ; i < size ; i++)
    {
        auto& ticket = tickets[i];
        string u = ticket[0];
        
        adj[u].push_back(i);
    }
    
    vector<bool> used(size);
    
    bool found = false;
    function<void(string, int)> dfs = [&](string cv, int depth)
    {
        // if (found) return;
        
        if (depth == size)
        {
            found = true;
            return;
        }
        
        for (int nt : adj[cv])
        {
            if (used[nt]) continue;
            used[nt] = true;
            
            string nv = tickets[nt][1];
            
            history.push_back(nv);
            dfs(nv, depth + 1);
            if (found) return;
            history.pop_back();
            
            used[nt] = false;
        }
    };
    
    dfs("ICN", 0);
    return history;
}