#include <bits/stdc++.h>
using namespace std;

// 떨어지는 위치 찾는 로직 구현
// 떨어뜨린 결과로 target을 만족시킬 수 있는지 확인, 처음으로 만족하는 경우가 떨어뜨리는 최소 횟수
// 그 과정에서 순서 기록
// 순서를 사전순 앞으로 해서 가능하도록 숫자 부여

const int NMX = 100;
int N;
vector<int> adj[NMX + 1];
int cur_child[NMX + 1];
int target[NMX + 1];

// target node 반환
int simulate()
{
    int cv = 1;
    
    while (cur_child[cv] > 0)
    {
        int nv = cur_child[cv];
        
        int next_cur_child = 0;
        auto it = upper_bound(adj[cv].begin(), adj[cv].end(), nv);
        
        if (it == adj[cv].end())
            next_cur_child = adj[cv][0];
        else
            next_cur_child = *it;
        
        cur_child[cv] = next_cur_child; 
        cv = nv;
    }
    
    return cv;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target_) {
    N = target_.size();
    copy(target_.begin(), target_.end(), target + 1);
    
    int remain = accumulate(target + 1, target + N + 1, 0);
    int target_num = accumulate(target + 1, target + N + 1, 0, 
                                [](int acc, int cur){ return acc + (cur > 0 ? 1 : 0); });

    for (const auto& edge : edges)
    {
        int p, c;
        p = edge[0];
        c = edge[1];
        
        adj[p].push_back(c);
    }
    
    for (int i = 1 ; i <= N ; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        if (adj[i].size() > 0)
            cur_child[i] = adj[i][0];
    }
    
    
    vector<bool> complete(N + 1);
    int complete_cnt = 0;
    vector<int> target_cnt(N + 1);
    vector<int> order;
    
    while (complete_cnt < target_num)
    {
        int tv = simulate();
        
        order.push_back(tv);
        target_cnt[tv]++;
        
        if (complete[tv]) continue;
        if (target_cnt[tv] * 3 >= target[tv]) 
        {
            complete[tv] = true;
            complete_cnt++;
        }
    }
    
    for (int tv : order)
    {
        if (target_cnt[tv] > target[tv])
            return {-1};
    }
    
    vector<int> ans;
    
    for (int tv : order)
    {
        int n = 3;
        if (target[tv] - 1 <= (target_cnt[tv] - 1) * 3)
            n = 1;
        else if (target[tv] - 2 <= (target_cnt[tv] - 1) * 3)
            n = 2;

        ans.push_back(n);
        target[tv] -= n;
        target_cnt[tv]--;
    }
    
    return ans;
}