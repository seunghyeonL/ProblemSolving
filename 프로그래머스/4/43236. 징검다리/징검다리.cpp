#include <bits/stdc++.h>
using namespace std;

// 구간을 need개로 합칠때 최소구간 길이의 최댓값
// 최소 길이가 특정 값 보다 작으면 항상 가능
// 최소 길이가 특정 값 보다 크면 항상 불가능
// -> 이분탐색

int need;
int N; // 구간 개수
vector<int> D;

// mn_len보다 큰 최소 길이로 구간을 만들어 나갈때
// 개수가 need개 이상인가 (need개보다 많을 경우 합치면 더 길어지니 need개로 만들 수 있음)
bool check(int mn_len)
{
    int pn = 0;
    int cl = 0;
    
    for (int i = 0 ; i < N ; i++)
    {
        cl += D[i];
        
        if (cl >= mn_len)
        {
            pn++;
            cl = 0;
        }
    }
    
    if (pn >= need)
        return true;
    else 
        return false;
}

int solution(int distance, vector<int> rocks, int n) 
{
    N = rocks.size() + 1;
    need = N - n;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    
    for (int i = 0 ; i < N ; i++)
        D.push_back(rocks[i + 1] - rocks[i]);
    
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;
        
        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }
    
    for (int i = 0 ; i < N ; i++)
        
    
    return r;
}