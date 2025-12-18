#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 정답이 ans일때
// t >= ans 이면 심사 가능
// t < ans 이면 심사 불가능

int N;
vector<int> times;

// 
bool check(ll t)
{
    // 심사 가능 사람 수
    ll n = 0;
    
    for (int ct : times)
    {
        n += t / ct;
    }
    
    if (n >= N) 
        return true;
    else 
        return false;
}

ll solution(int n, vector<int> _times) 
{
    N = n;
    times = _times;
    
    ll l = 1, r = 1e18;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        
        if (check(m))
            r = m - 1;
        else
            l = m + 1;       
    }
    
    return l;
}