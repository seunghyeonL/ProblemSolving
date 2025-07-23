#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y <= m;  
    };
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    vector<pair<int, int>> moveDirection{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty())
    {
        auto [cX, cY] = q.front();
        q.pop();
        
        if (cX == n -1 && cY == m - 1)
        {
            answer = dist[cX][cY];
            break;
        }
        
        for (auto [dX, dY] : moveDirection)
        {
            int nX = cX + dX;
            int nY = cY + dY;
            
            if (isValid(nX, nY) && dist[nX][nY] == -1 && maps[nX][nY])
            {
                q.push({nX, nY});
                dist[nX][nY] = dist[cX][cY] + 1;
            }
        }
    }
    
    return answer;
}