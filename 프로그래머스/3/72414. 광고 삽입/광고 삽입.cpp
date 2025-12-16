#include <bits/stdc++.h>
using namespace std;

// 100h = 6000m = 360000s
const int MX = 360000;
long long arr[MX]; // arr[t] : t초에 보는 시청자 수
long long D[MX + 1]; // 차분
long long P[MX + 1]; // 누적합

int pt, at;

int to_second(const string& str)
{
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6, 2));
    
    return 3600 * h + 60 * m + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    memset(arr, 0, sizeof(arr));
    memset(D, 0, sizeof(D));
    memset(P, 0, sizeof(P));
    
    pt = to_second(play_time);
    at = to_second(adv_time);
    
    for (auto& log : logs)
    {
        int st = to_second(log.substr(0, 8));
        int et = to_second(log.substr(9, 8));
        
        D[st] += 1;
        D[et] -= 1;
    }
    
    inclusive_scan(D, D + pt, arr);
    inclusive_scan(arr, arr + pt, P + 1);
    
    long long mx = 0;
    int mx_t = 0;
    for (int t = 0 ; t <= pt - at ; t++)
    {
        if (mx < P[t + at] - P[t])
        {
            mx = P[t + at] - P[t];
            mx_t = t;
        }
    }
    
    stringstream ss;
    
    string h = to_string(mx_t / 3600);
    if (h.size() == 1)
        h = "0" + h;
    
    mx_t %= 3600;
    
    string m = to_string(mx_t / 60);
    if (m.size() == 1)
        m = "0" + m;
    
    mx_t %= 60;
    
    string s = to_string(mx_t);
    if (s.size() == 1)
        s = "0" + s;
    
    ss << h << ':' << m << ':' << s;

    return ss.str();
}