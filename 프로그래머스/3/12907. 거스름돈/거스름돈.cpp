#include <bits/stdc++.h>
using namespace std;

// 0-1 무한배낭

const int NMX = 100'000;
int N;
int dp[NMX + 1];

int solution(int n, vector<int> money) 
{
    N = n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    // ---
    
    for (int coin : money)
    {
        for (int i = coin ; i <= N ; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[N];
}