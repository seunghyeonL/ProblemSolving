#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 도시에 금 a, 은 b 전달

// 각 도시마다 금 은 보유량 존재
// 각 도시에서 2t 에 w씩 운반 가능 (마지막은 t)

// 최소시간 : ans
// t < ans => 불가능
// t >= ans => 가능
// 이분탐색

int g_need, s_need;
int N;
vector<int> g, s, w, t;

// idx 도시에서 mt 시간에 가능한 최대 운반량
__int128 get_w_mt(int idx, ll mt)
{
    int cw = w[idx];
    int ct = t[idx];
    
    __int128 n = mt / ct;
    
    return (n / 2) * cw + (n % 2) * cw;
}

// mt시간 안에 도시 건설이 가능한가?
// g_need <= sum min(g[idx], get_w_mt(idx, mt))
// s_need <= sum min(s[idx], get_w_mt(idx, mt))
// g_need + s_need <= sum min(g[idx] + s[idx], get_w_mt(idx, mt));
bool check(ll mt)
{
    __int128 sum1 = 0;
    __int128 sum2 = 0;
    __int128 sum3 = 0;
    
    for (int i = 0 ; i < N ; i++)
    {
        __int128 w_mt = get_w_mt(i, mt);
        sum1 += min(__int128(g[i]), w_mt);
        sum2 += min(__int128(s[i]), w_mt);
        sum3 += min(__int128(g[i] + s[i]), w_mt);
    }
    
    return g_need <= sum1 && s_need <= sum2 && g_need + s_need <= sum3;
}

ll solution(int _a, int _b, vector<int> _g, vector<int> _s, vector<int> _w, vector<int> _t) 
{
    g_need = _a;
    s_need = _b;
    g = _g;
    s = _s;
    w = _w;
    t = _t;
    N = g.size();
        
    ll l = 0, r = 1e18;
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