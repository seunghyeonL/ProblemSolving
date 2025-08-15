#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    const int INF = 1e8;
    int answer = INF;
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1 ; i <= n ; i++)
    {
         dist[i][i] = 0;
    }
    
    for(auto fare : fares)
    {
        int c = fare[0];
        int d = fare[1];
        int f = fare[2];
        
        dist[c][d] = f;
        dist[d][c] = f;
    }
    
    
    for (int k = 1 ; k <= n ; k++)
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= n ; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    for (int i = 1 ; i <= n ; i++)
    {
        answer = min(answer, dist[i][s] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}