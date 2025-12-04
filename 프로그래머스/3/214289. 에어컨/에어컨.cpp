#include <bits/stdc++.h>
using namespace std;

const int TMX = 50;
const int INF = 1000000000;
// dp[i][j] : i분에 온도를 j로 할때의 최소 비용
int dp[1000][TMX + 1];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF;
    // 온도를 10도 올려서 생각하기
    temperature += 10;
    t1 += 10;
    t2 += 10;
    
    int sz = onboard.size();
    int last_idx = sz - 1;
    for (int i = sz - 1 ; i >= 0 ; i--)
        if (onboard[i]) { last_idx = i; break;}
    
    for (int i = 0 ; i < sz ; i++)
    {
        for (int j = 0 ; j <= TMX ; j++)
        {
            dp[i][j] = INF;
        }
    }
    
    dp[0][temperature] = 0;
    
    bool is_down = temperature < t1;
    
    for (int time = 1 ; time < sz ; time++)
    {
        int st = onboard[time] ? t1 : 0;
        int et = onboard[time] ? t2 : TMX;
            
        for (int ct = st ; ct <= et ; ct++)
        {
            if (ct > 0) dp[time][ct] = min(dp[time][ct], dp[time - 1][ct - 1] + (is_down ? a : 0));
            
            dp[time][ct] = min(dp[time][ct], dp[time - 1][ct] + (ct == temperature ? 0 : b));
            
            if (ct < TMX) dp[time][ct] = min(dp[time][ct], dp[time - 1][ct + 1] + (is_down ? 0 : a));
        }
    }
    
    for (int t = t1 ; t <= t2 ; t++)
    {
        answer = min(answer, dp[last_idx][t]);
    }
    
    return answer;
}