#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// enemy 길이가 1000000 -> 완전탐색 불가

// 막을수 있는 최대 라운드 : ans
// ans 이하 라운드에서 막을 수 있는가? -> true
// ans 이하 라운드에서 막을 수 있는가? -> false


// mx_rn 라운드 동안 막을 수 있는가?
// <=> 
// 범위에서 제일 큰 K개의 라운드에 우선권을 썼을때 가능한가?

int N;
int K;
vector<int> enemy;

bool check(int mx_rn)
{
    priority_queue<int> pq(enemy.begin(), enemy.begin() + mx_rn);
    
    ll cw = accumulate(enemy.begin(), enemy.begin() + mx_rn, 0LL);
    
    for (int i = 0 ; i < K ; i++)
    {
        if (pq.empty())
            break;
        
        cw -= pq.top();
        pq.pop();
    }
    
    if (cw <= N)
        return true;
    else 
        return false;
}


int solution(int n, int k, vector<int> _enemy) 
{
    N = n;
    K = k;
    enemy = _enemy;
    
    int l = 0, r = enemy.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m))
            l = m + 1;
        else 
            r = m - 1;
    }
    
    return r;
}