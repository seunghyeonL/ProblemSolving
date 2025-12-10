#include <bits/stdc++.h>
using namespace std;

// a1 + a2 + ... + ak == n 으로 나누는 경우 완전 탐색

using P = pair<int, int>;
const int KMX = 5;
int K, N;

queue<P> waiting[KMX + 1]; // {요청 시간, 소요 시간}
vector<int> desk[KMX + 1]; // 상담 끝 시간 기록

int run(int c)
{
    queue<P>& q = waiting[c];
    vector<int>& v = desk[c];
    
    int wt = 0;
    
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        
        int st = a; // 상담 시작 시간
        
        // 가장 빨리 끝나는 상담원에게로
        auto mn_et_it = min_element(v.begin(), v.end());     
        int mn_et = *mn_et_it;
        
        st = max(st, mn_et);
        wt += st - a;
        
        *mn_et_it = st + b;
    }
    
    return wt;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K = k;
    N = n;
    
    vector<int> mask(N, 0);
    fill(mask.begin(), mask.begin() + K - 1, 1);
    mask[N - 1] = 1;
    
    int ans = 1e9;
    do
    {
        int idx = 1;
        int cur = 0;
        for (int b : mask)
        {
            if (b) 
            {
                desk[idx++].assign(++cur, 0);
                cur = 0;
            }
            else
                ++cur;
        }
        
        for (const auto& req : reqs)
        {
            int a = req[0];
            int b = req[1];
            int c = req[2];
            
            waiting[c].emplace(a, b);
        }
        
        int wt_acc = 0;
        for (int t = 1 ; t <= K ; t++)
            wt_acc += run(t);
        
        ans = min(ans, wt_acc);
        
    } while(prev_permutation(mask.begin(), prev(mask.end())));
    
    
    return ans;
}