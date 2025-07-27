#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    using P = pair<int, int>;
    
    int answer = 0;
    int N = arrows.size();
    
    map<P, bool> visited;
    map<pair<P, P>, bool> usedEdge;
    
    vector<P> directions{
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1}
    };
    
    int cx = 0 , cy = 0;
    visited[{0, 0}] = true;
    
    for (int arrow : arrows)
    {
        for (int _ = 0 ; _ < 2 ; _++)
        {
            auto [dx, dy] = directions[arrow];
            int nx = cx + dx;
            int ny = cy + dy;

            P preNode = {cx, cy};
            P nextNode = {nx, ny};

            if (visited.find(nextNode) != visited.end() &&
                usedEdge.find({preNode, nextNode}) == usedEdge.end()) answer++;

            visited[nextNode] = true;
            usedEdge[{preNode, nextNode}] = true;
            usedEdge[{nextNode, preNode}] = true;
            cx = nx;
            cy = ny;
        }
    }
    
    return answer;
}