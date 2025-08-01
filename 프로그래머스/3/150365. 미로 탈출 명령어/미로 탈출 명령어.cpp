#include <string>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    using T = tuple<char, int, int>;
    string answer = "z";
    
    x -= 1;
    y -= 1;
    r -= 1;
    c -= 1;
    
    auto getDistance = [](int x1, int y1, int x2, int y2)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    };
    
    int dist = getDistance(x, y, r, c);
    if (abs(k - dist) % 2 != 0) return "impossible";
    
    vector<T> directions
    {
        {'d', 1, 0},
        {'l', 0, -1},
        {'r', 0, 1},
        {'u', -1, 0}
    };
    
    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;  
    };
    
    string path{};
    bool endflag = false;
    
    function<void(int, int)> dfs = [&](int cx, int cy)
    {
        if (endflag) return;
        // 남은 이동 횟수 < 도착점까지 거리
        if (k - path.size() < getDistance(cx, cy, r, c)) return;
        
        if (path.size() == k)
        {
            if (cx == r && cy == c)
            {
                answer = path;
                endflag = true;
            }
            
            return;
        }
        
        for (auto [chr, dx, dy] : directions)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (isValid(nx, ny))
            {
                path.push_back(chr);
                dfs(nx, ny);
                path.pop_back();
            }
        }
    };
    
    dfs(x, y);
    
    return answer == "z" ? "impossible" : answer;
}