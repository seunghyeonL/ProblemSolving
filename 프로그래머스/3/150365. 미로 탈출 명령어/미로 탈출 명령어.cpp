#include <string>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    using T = tuple<char, int, int>;
    string answer{};
    
    x -= 1;
    y -= 1;
    r -= 1;
    c -= 1;
    
    auto getDistance = [](int x1, int y1, int x2, int y2)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    };
    
    int dist = getDistance(x, y, r, c);
    if ((k - dist) % 2 != 0 || k < dist) return "impossible";
    
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
    
    int cx = x;
    int cy = y;
    
    while (k > 0)
    {
        k--;
        int px = cx;
        int py = cy;
        
        for (auto [chr, dx, dy] : directions)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!isValid(nx, ny) || getDistance(nx, ny, r, c) > k) continue;
            
            answer.push_back(chr);
            cx = nx;
            cy = ny;
            break;
        }
        
        if (px == cx && py == cy) return "impossible";
    }
    
    return answer;
}