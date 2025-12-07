#include <bits/stdc++.h>
using namespace std;

long long limit_e;
int N;
vector<int> diffs_e;
vector<int> times_e;

// 제한시간내 풀 수 있는가?
bool check(int level)
{
    long long need = 0;
    
    for (int i = 0 ; i < N ; i++)
    {
        int d = diffs_e[i];
        int ct = times_e[i];
        int pt = times_e[i - 1];
        
        if (d > level)
        {
            need += ((long long)ct + pt) * (d - level);
        }

        need += ct;
        
        if (need > limit_e)
            break;
    }
    
    return need <= limit_e;
}

int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    N = diffs.size();
    limit_e = limit;
    diffs_e = diffs;
    times_e = times;
    
    int l = 1, r = 100'000;
    while (l <= r)
    {
        int m = (l + r) / 2;
        
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }
    
    return l;
}