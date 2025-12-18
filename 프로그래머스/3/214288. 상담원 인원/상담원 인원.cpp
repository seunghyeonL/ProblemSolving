#include <bits/stdc++.h>
using namespace std;

// 상담을 원하는 참가자가 상담 요청을 했을 때, 참가자의 상담 유형을 담당하는 멘토 중 상담 중이 아닌 멘토와 상담을 시작합니다.

// 만약 참가자의 상담 유형을 담당하는 멘토가 모두 상담 중이라면, 자신의 차례가 올 때까지 기다립니다. 참가자가 기다린 시간은 참가자가 상담 요청했을 때부터 멘토와 상담을 시작할 때까지의 시간입니다.

// 모든 멘토는 상담이 끝났을 때 자신의 상담 유형의 상담을 받기 위해 기다리고 있는 참가자가 있으면 즉시 상담을 시작합니다. 이때, 먼저 상담 요청한 참가자가 우선됩니다.

// --

// 상담 요청을 유형별로 q로 관리
// 각 유형별로 멘토 수 == 최대 사이즈 의 (상담 끝 시간) 요소 priority_queue로 상담 관리 
// 유형별 멘토 수 배정은 완전탐색 -> 2^20 ~= 1000000

const int INF = 1e9;
vector<queue<pair<int, int>>> qs;
vector<int> m_nums;

int solution(int k, int n, vector<vector<int>> reqs) 
{
    qs.clear();
    m_nums.clear();
    
    qs.resize(k + 1);
    m_nums.resize(k + 1);
    
    vector<int> mask(n); // 분할한 끝 point를 1로
    mask.back() = 1;
    fill(mask.begin(), mask.begin() + k - 1, 1);

    int ans = INF;
    
    do
    {
        {
            int ti = 1;
            int s = -1;
            for (int e = 0 ; e < n ; e++)
            {
                if (mask[e] == 1)
                {
                    m_nums[ti++] = e - s;
                    s = e;
                }
            }
        }
        
        int wt = 0;
        
        for (const auto& req : reqs)
        {
            int a = req[0];
            int b = req[1];
            int c = req[2];

            qs[c].emplace(a, b);
        }
    
        for (int ti = 1 ; ti <= k ; ti++)
        {
            auto& q = qs[ti];
            int mx_sz = m_nums[ti];
            priority_queue<int, vector<int>, greater<int>> pq;
            
            while (!q.empty())
            {
                auto [st, dt] = q.front();
                q.pop();
                
                while (!pq.empty() && pq.top() <= st)
                {
                    pq.pop();
                }
                
                if (pq.size() < mx_sz) 
                {
                    pq.push(st + dt);
                }
                else
                {

                    wt += pq.top() - st;
                    st = pq.top();
                    pq.pop();

                    pq.push(st + dt);  
                }
            }
        }
        
        ans = min(ans, wt);
        
    } while(prev_permutation(mask.begin(), prev(mask.end())));
    
    return ans;
}