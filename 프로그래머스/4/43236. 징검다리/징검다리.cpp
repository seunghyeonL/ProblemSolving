#include <bits/stdc++.h>

using namespace std;

// 모든 구간 거리를 mn_d 보다 크게 할때 구간 개수가 need개 이상인가?
// (n 이상일 경우 구간 몇개를 합쳐서 n개로 만들기 가능)
// mn_d =< ans -> true
// mn_d > ans -> false

bool check(int mn_d, const vector<int>& dists, const int need)
{
    const int sz = dists.size();
    
    int pn = 0;
    int cur = 0;
    
    for (int d : dists)
    {
        cur += d;
        if (cur >= mn_d)
        {
            pn++;
            cur = 0;
        }
    }
    
    return pn >= need;
}


int solution(int distance, vector<int> rocks, int n) {
    const int N = rocks.size() + 1;
    const int need = N - n;
    
    sort(rocks.begin(), rocks.end());
    
    vector<int> dists;
    dists.reserve(N);
    
    dists.push_back(rocks[0]);
    for (int i = 1 ; i < N - 1 ; i++)
        dists.push_back(rocks[i] - rocks[i - 1]);
    dists.push_back(distance - rocks.back());
    
    int l = 1, r = distance;
    while (l <= r)
    {
        int m = (l + r) / 2;
        
        if (check(m, dists, need))
            l = m + 1;
        else
            r = m - 1;
    }
    
    return r;
}