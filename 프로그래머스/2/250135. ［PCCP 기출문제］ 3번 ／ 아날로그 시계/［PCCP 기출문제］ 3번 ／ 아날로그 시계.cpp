#include <bits/stdc++.h>
using namespace std;

// 한바퀴가 1일때 각 바늘은 1초에
// 시침은 12 * 60 * 60초에 한바퀴 -> 1 / 12 * 60 * 60
// 분침은 60 * 60 초에 한바퀴 ->  1 / (60 * 60)
// 초침은 60초 한바퀴 ->  1 / 60

// 한바퀴를 12 *60 *60 으로 처리
// 시침은 1초에 1
// 분침은 1초에 12
// 초침은 1초에 60 * 12 = 720

const int MOD = 12 * 60 * 60;

int pos_h;
int pos_m;
int pos_s;

int get_sec(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int t1 = get_sec(h1, m1, s1);
    int t2 = get_sec(h2, m2, s2);
    
    pos_h = t1 % MOD;
    pos_m = t1 * 12 % MOD;
    pos_s = t1 * 720 % MOD;
    
    int ans = 0;    
    int ct = t1;

    while (ct <= t2)
    {
        if (pos_m == pos_s || pos_s == pos_h) ans++;
        if (ct == t2) break;
        
        int p_pos_h = pos_h;
        int p_pos_m = pos_m;
        int p_pos_s = pos_s;
        
        ct++;
        pos_h += 1;
        pos_m += 12;
        pos_s += 720;
        
        if (p_pos_h > p_pos_s && pos_h < pos_s) ans++;
        if (p_pos_m > p_pos_s && pos_m < pos_s) ans++;
        
        pos_h %= MOD;
        pos_m %= MOD;
        pos_s %= MOD;
    }

    return ans;
}