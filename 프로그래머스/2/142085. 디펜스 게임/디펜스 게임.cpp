#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// enemy 길이가 1000000 -> 완전탐색 불가
// for e : enemy
// priority_queue에 e를 넣고 
// e를 합치며
// 안쓰면 죽을때 그동안 e 중 최대에 무적권 사용

// 죽거나 enemy가 끝날때 까지

int solution(int n, int k, vector<int> enemy) 
{
    int N = n;
    int K = k;
    
    priority_queue<int> pq;
    
    int ans = 0;
    ll acc = 0;
    
    for (int e : enemy)
    {
        pq.push(e);
        acc += e;
        
        if (acc > N)
        {
            while (acc > N && K > 0 && !pq.empty())
            {
                K--;
                acc -= pq.top();
                pq.pop();
            }
            
            // 막기 실패
            if (acc > N)
                break;
        }
        
        // 이번 라운드 성공
        ans++;
    }
    
    
    return ans;
}