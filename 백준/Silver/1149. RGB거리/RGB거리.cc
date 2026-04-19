#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

int main () {
    int N;
    int r,g,b;
    int dp[1000][3];
    std::cin >> N;

    for(int i=1;i<=N;i++) {
        std::cin >> r >> g >> b;
        dp[i][0] = min(dp[i-1][1]+r, dp[i-1][2]+r);
        dp[i][1] = min(dp[i-1][0]+g, dp[i-1][2]+g);
        dp[i][2] = min(dp[i-1][0]+b, dp[i-1][1]+b);
    }
    
    std::cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
    return 0;
}