#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getDistancePow(pair<int, int> a, pair<int, int> b)
{
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    pair<int, int> start = {startX, startY};
    
    for(auto ball : balls)
    {
        int ballX = ball[0];
        int ballY = ball[1];
        
        // y = 0 대칭
        pair<int, int> pos1 = {ballX, 0 - ballY};
        
        // x = 0 대칭
        pair<int, int> pos2 = {0 - ballX, ballY};
        
        // y = n 대칭
        pair<int, int> pos3 = {ballX, 2 * n - ballY};
        
        // x = m 대칭
        pair<int, int> pos4 = {2 * m - ballX, ballY};
        
        answer.push_back(min(
            {startX == ballX && startY > ballY ? pow(2 * m + 2 * n, 2)
                                               : getDistancePow(start, pos1),
             startY == ballY && startX > ballX ? pow(2 * m + 2 * n, 2)
                                               : getDistancePow(start, pos2),
             startX == ballX && startY < ballY ? pow(2 * m + 2 * n, 2)
                                               : getDistancePow(start, pos3),
             startY == ballY && startX < ballX ? pow(2 * m + 2 * n, 2)
                                               : getDistancePow(start, pos4)}));
    }
    
    return answer;
}