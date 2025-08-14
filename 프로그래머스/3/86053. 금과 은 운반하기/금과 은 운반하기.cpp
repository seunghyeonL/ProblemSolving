#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    using ll = long long;
    int size = g.size();
    const ll INF = (ll)1e15;
    
    ll answer = -1;
    
    // 시간을 기준으로 이분탐색
    // 각 도시에서 time 시간동안 운반 가능한 광물 무게 wt :
    // time / (2 * t[i]) * w[i] + (time % (2 * t[i]) >= t[i] ? 1 : 0)
    
    // 성공적으로 운반할 조건 :
    // a <= min(g[i], wt[i]) 합 && b <= min(s[i], wt[i]) 합 && a + b <= min(g[i] + s[i], wt[i]) 합
    // 세 조건을 만족하는데 한 쪽 광물이 시간안에 운송이 불가능하다고 가정할때
    // 가능한 쪽에서 
    
    auto getwt = [&](ll time, int i) -> ll
    {
        ll wi = ll(w[i]);
        ll ti = ll(t[i]);
        ll trips = time / (2 * ti) + (time % (2 * ti) >= ti ? 1 : 0);
        return wi * trips;
    };
    
    auto check = [&](ll time) -> bool
    {
        ll gPossible = 0, sPossible = 0, bothPossible = 0;
        
        for (int i = 0 ; i < size ; i++)
        {
            ll wt = getwt(time, i);
            ll gi = ll(g[i]);
            ll si = ll(s[i]);
            
            gPossible += min<ll>(gi, wt);
            sPossible += min<ll>(si, wt);
            bothPossible += min<ll>(gi + si, wt);
        }
        
        return a <= gPossible && b <= sPossible && a + b <= bothPossible;
    };
    
    ll left = 0;
    ll right = INF;
    
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        
        if (check(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}