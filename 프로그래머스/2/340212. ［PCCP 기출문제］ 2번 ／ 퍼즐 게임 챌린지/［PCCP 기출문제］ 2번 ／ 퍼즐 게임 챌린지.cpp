#include <bits/stdc++.h>
using namespace std;

// 레벨이 높아질수록 푸는 시간이 단조 감소
// 이분탐색

int N; // 문제 개수
vector<int> diffs;
vector<int> times;
long long limit;


// 현재 레벨로 제한시간내 풀이 가능
bool check(int level)
{
    long long ct = 0;
    
    for (int i = 0 ; i < N ; i++)
    {  
        if (diffs[i] > level)        
        {
            int n = diffs[i] - level;
            
            while (--n >= 0)
            {
                // 첫 문제는 틀리지 않음
                ct += times[i] + times[i - 1];
            }
        }
        
        ct += times[i];
        
        if (ct > limit)
            return false;
    }
    
    return true;
}

int solution(vector<int> _diffs, vector<int> _times, long long _limit) 
{
    N = _diffs.size();
    diffs = _diffs;
    times = _times;
    limit = _limit;
    
    int l = 1, r = 300000;
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