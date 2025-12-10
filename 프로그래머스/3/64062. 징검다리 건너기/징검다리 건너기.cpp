#include <bits/stdc++.h>
using namespace std;

// 건널 수 있는 사람은 ans 이상이면 못건너고 ans 이하면 건널 수 있음
// 이분탐색

const int LMT = 200'000'000;
int K, L;
vector<int> i_stones; // 초기 상태
vector<int> c_stones;

// n명이 건널 수 있는가?
bool check(int n)
{
    // 모든 돌에서 n - 1을 뺐을때 최대 연속 0 이하 개수가 K보다 작아야 건널 수 있음
    c_stones = i_stones;
    
    for (int& val : c_stones)
        val -= (n - 1);
    
    int mx_0_len = 0;
    // i : 연속 0 이하 이전 idx, j : 현재 idx
    for (int i = -1, j = 0 ; j <= L ; j++)
    {
        if (j == L)
        {
            mx_0_len = max(mx_0_len, j - i - 1);
            break;
        }
        
        if (c_stones[j] <= 0) continue;
        
        mx_0_len = max(mx_0_len, j - i - 1);
        i = j;
    }
    
    return mx_0_len < K;
}

int solution(vector<int> stones, int k) {
    K = k;
    L = stones.size();
    i_stones = stones;
    
    int l = 0, r = LMT;
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