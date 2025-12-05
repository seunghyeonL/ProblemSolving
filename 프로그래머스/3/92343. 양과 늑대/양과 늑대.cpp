#include <bits/stdc++.h>
using namespace std;

// 현재 방문한 노드에 따라 갈 수 있는 노드가 달라진다.

const int NMX = 17;
int N;
vector<int> is_wolf;
vector<int> adj[NMX];
int memo[1 << NMX]; // memo[mask] : mask 상태부터 시작해서 새로 얻을 수 있는 최대 양 개수

// mask : cv를 포함한 살펴본 노드 정보
void dfs(int sn, int wn, int mask)
{
    if (memo[mask]) return;
    memo[mask] = sn;
    
    bool can_wolf = (sn >= wn + 2);

    for (int cv = 0 ; cv < N ; cv++)
    {
        if ((mask >> cv) & 1)
        {
            for (int nv : adj[cv])
            {
                if ((mask >> nv) & 1) continue;

                if (is_wolf[nv] && !can_wolf) continue;

                dfs(sn + !is_wolf[nv], wn + is_wolf[nv], mask | (1 << nv));
            }
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();
    is_wolf = info;
    
    for (const auto& edge : edges)
    {
        int p = edge[0];
        int c = edge[1];
        
        adj[p].push_back(c);
    }
    
    dfs(1, 0, 1);
    
    return *max_element(memo, memo + (1 << N));
}