#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// t 초에 가능한가?
// t < ans => false
// t >= ans => true

bool check(ll t, const int n, const vector<int>& times)
{
    // t초에 심사 가능한 인원
    ll total = accumulate(times.begin(), times.end(), 0LL, [&](ll acc, ll cur){
        return acc += t / cur;
    });
    
    return total >= n;
}

long long solution(int n, vector<int> times) {
    
    ll l = 1, r = 1e18;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        
        if (check(m, n, times))
            r = m - 1;
        else 
            l = m + 1;
    }
    
    return l;
}