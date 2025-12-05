#include <bits/stdc++.h>
using namespace std;

const int NMX = 200;
const long long INF = 1e15;

long long dist[NMX + 1][NMX + 1];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{    
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            dist[i][j] = INF;
    
    for (const auto& fare : fares)
    {
        int u = fare[0];
        int v = fare[1];
        int w = fare[2];
        
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    for (int i = 1 ; i <= n ; i++)
        dist[i][i] = 0;
    
    for (int k = 1 ; k <= n ; k++)
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= n ; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    long long mn_cost = INF;
    for (int i = 1 ; i <= n ; i++)
    {
        mn_cost = min(mn_cost, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return mn_cost;
}