#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <limits>
#include <tuple>

using namespace std;
using ll = long long;

tuple <int, int, bool> getIntersection(const vector<int>& line1, const vector<int>& line2)
{
    int A = line1[0];
    int B = line1[1];
    int C = line2[0];
    int D = line2[1];
    int E = line1[2];
    int F = line2[2];
    
    if((ll)A*D - (ll)B*C == 0) return {0, 0, false};
    if(((ll)B*F - (ll)E*D) % ((ll)A*D - (ll)B*C) != 0) return {0, 0, false};
    if(((ll)E*C - (ll)A*F) % ((ll)A*D - (ll)B*C) != 0) return {0, 0, false};
    
    return {((ll)B*F - (ll)E*D)/ll((ll)A*D - (ll)B*C), ((ll)E*C - (ll)A*F)/((ll)A*D - (ll)B*C), true};
}

vector<string> solution(vector<vector<int>> line) {
    int size = line.size();
    
    set<pair<int, int>> s;
    
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();
    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    
    for(int i = 0 ; i < size - 1; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            auto [x, y, intersectFlag] = getIntersection(line[i], line[j]);
            if(!intersectFlag) continue;
            
            if(x > maxX) maxX = x;
            if(x < minX) minX = x;
            if(y > maxY) maxY = y;
            if(y < minY) minY = y;

            s.insert({x, y});
        }
    }
    
    int N = maxX - minX + 1;
    int M = maxY - minY + 1;
    
    cout << "X: " << minX << " " << maxX << '\n';
    cout << "Y: " << minY << " " << maxY << '\n';
    

    int minXDiffZero = 0 - minX;
    int minYDiffZero = 0 - minY;
    
    vector<string> answer(M, string(N, '.'));
    
    for(auto [x, y] : s)
    {
        x += minXDiffZero;
        y += minYDiffZero;
        
        y = M - y - 1;
        
        answer[y][x] = '*';
    }
    
    return answer;
}