#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    vector<int> p(n, -1);
    
    function<int(int)> findRoot = [&](int u) -> int
    {
        if(p[u] < 0) return u;
        
        return p[u] = findRoot(p[u]);
    };
    
    auto unionSet = [&](int u, int v) -> bool
    {
        u = findRoot(u);
        v = findRoot(v);
        
        if(u == v) return false;
        
        if(p[u] < p[v])
        {
            p[v] = u; 
        }
        else if(p[u] == p[v])
        {
            p[v] = u;
            p[u]--;
        }
        else
        {
            p[u] = v;
        }
        return true;
    };
    
    sort(costs.begin(), costs.end(), [](auto a, auto b){ return a[2] < b[2]; });
    
    int result = 0;
    
    for(auto edgeCost : costs)
    {
        int u = edgeCost[0];
        int v = edgeCost[1];
        int cost = edgeCost[2];
        
        if (unionSet(u, v))
        {
            result += cost;
        }
    }
    
    return result;
}