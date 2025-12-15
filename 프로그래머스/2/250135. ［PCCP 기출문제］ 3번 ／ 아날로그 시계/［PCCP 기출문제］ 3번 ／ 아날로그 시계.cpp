#include <bits/stdc++.h>
using namespace std;

// 시침 주기 : 12시간 = 12 * 60 * 60 = 43200 초
// 분침 주기 : 1시간 = 60 * 60 = 3600 초
// 초침 주기 : 60 초

// 초침과 분침은 1시간에 3600 / 60 - 3600 / 3600 = 59번 겹침
// 초침과 시침은 12시간에 43200 / 60 - 43200 / 43200 = 720 - 1 = 719번 겹침

// 초침과 분침은 1초에 59 / 3600
// 초침과 시침은 1초에 719 / 43200;

// 시간간격 diff 초 동안
// 초침 + 분침 => diff * 59 / 3600 번 알람
// 초침 + 시침 => diff * 719 / 43200 번 알람

// 00시, 12시에는 겹쳐서 울려서 고려해주기

int to_second(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) 
{
    const int t_12 = to_second(12, 0, 0);
    
    int ans = 0;
    
    int t1 = to_second(h1, m1, s1);
    int t2 = to_second(h2, m2, s2);
    
    int diff = t2 - t1;
    
    ans += t2 * 59 / 3600;
    ans += t2 * 719 / 43200;
    
    ans -= t1 * 59 / 3600;
    ans -= t1 * 719 / 43200;
    
    if (t1 < t_12 && t2 >= t_12)
        ans--;
    
    // t1 시간에 정확히 겹쳐있으면 알람 울려야함
    
    // 시침속도 : 1초에 1
    // 분침속도 : 43200 / 3600 = 12
    // 초침속도 : 43200 / 60 = 720
    int start_pos_h = t1 * 1 % 43200;
    int start_pos_m = t1 * 60 % 43200;
    int start_pos_s = t1 * 720 % 43200;
    
    if (start_pos_h == start_pos_s || start_pos_m == start_pos_s) 
        ans++;
    
    return ans;
}