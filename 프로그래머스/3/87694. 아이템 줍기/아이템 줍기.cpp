#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (auto& r : rectangle)
    {
        for (int& el : r)
        {
            el *= 2;
        }
    }
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    vector<vector<int>> borderPoints(101, vector<int>(101, 0));
    vector<vector<int>> dist(101, vector<int>(101, -1));
    
    vector<pair<int, int>> moveDirection{{0, 1}, {1, 0}, {-1, 0}, {0, -1},};
    
    auto isValid = [](int x, int y)
    {
        return x >= 0 && x <= 100 && y >= 0 && y <= 100;
    };
    
    for (const auto& r : rectangle)
    {
        int x1 = r[0];
        int y1 = r[1];
        int x2 = r[2];
        int y2 = r[3];
        
        for (int i = x1 ; i <= x2 ; i++)
            for (int j = y1 ; j <= y2 ; j++)
                borderPoints[i][j] = 1;
    }
                                    
    for (const auto& r : rectangle)
    {
        int x1 = r[0];
        int y1 = r[1];
        int x2 = r[2];
        int y2 = r[3];
        
        for (int i = x1 + 1 ; i < x2 ; i++)
            for (int j = y1 + 1 ; j < y2 ; j++)
                borderPoints[i][j] = 0;
    }
    
    queue<pair<int, int>> q;

    q.emplace(characterX, characterY);
    dist[characterX][characterY] = 0;
    
    while (!q.empty())
    {
        auto [cX, cY] = q.front();
        q.pop();
        
        if (cX == itemX && cY == itemY)
        {
            answer = dist[cX][cY];
            break;
        }
        
        for (auto [dX, dY] : moveDirection)
        {
            int nX = cX + dX;
            int nY = cY + dY;
            if (isValid(nX, nY) && dist[nX][nY] == -1 && borderPoints[nX][nY])
            {
                q.emplace(nX, nY);
                dist[nX][nY] = dist[cX][cY] + 1;
            }
        }
    }
    
    return answer / 2;
}
