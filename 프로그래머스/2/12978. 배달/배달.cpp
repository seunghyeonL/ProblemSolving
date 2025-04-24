#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    
    vector<vector<long long>> dist(N+1, vector<long long>(N+1, 5000001));
    
    for(int i = 1 ; i <= N ; i++)
    {
        dist[i][i] = 0;
    }
    
    for(auto roadInfo : road)
    {
        int a = roadInfo[0];
        int b = roadInfo[1];
        long long c = roadInfo[2];
        
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    for(int k = 1 ; k <= N ; k++)
    {
        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = 1 ; j <= N ; j++)
            {
                
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i = 1 ; i <= N ; i++)
    {
        if(dist[1][i] <= K) answer++;
    }
    return answer;
}