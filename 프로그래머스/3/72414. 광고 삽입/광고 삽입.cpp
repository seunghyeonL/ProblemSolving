#include <bits/stdc++.h>
using namespace std;

/*
100h == 6000m == 360000s

*/

const int MX = 360000;
int N, L;
int arr[MX];
int D[MX];
long long P[MX + 1];

int get_time(const string& ts)
{
    return stoi(ts.substr(0, 2)) * 3600 + stoi(ts.substr(3, 2)) * 60 + stoi(ts.substr(6, 2));
}

string solution(string play_time, string adv_time, vector<string> logs) {   
    N = get_time(play_time);
    L = get_time(adv_time);
    
    for (const string& log : logs)
    {
        int st = get_time(log.substr(0, 8));
        int et = get_time(log.substr(9, 8));
        
        D[st] += 1;
        D[et] -= 1;
    }
    
    for (int i = 1 ; i < N ; i++)
    {
        D[i] += D[i - 1];
    }
    
    for (int i = 0 ; i < N ; i++)
    {
        arr[i] += D[i];
    }
    
    for (int i = 1 ; i <= N ; i++)
    {
        P[i] = P[i - 1] + arr[i - 1];
    }
    
    long long mx_time = 0; 
    int ans_time = 0;
    for (int i = 0 ; i <= N - L ; i++)
    {
        if (mx_time < P[i + L] - P[i]) 
        {
            mx_time = P[i + L] - P[i];
            ans_time = i;
        }
    }
    
    string h = to_string(ans_time / 3600);
    if (h.size() < 2) 
        h = "0" + h;
    
    ans_time %= 3600;
    
    string m = to_string(ans_time / 60);
    if (m.size() < 2) 
        m = "0" + m;
    
    ans_time %= 60;
    
    string s = to_string(ans_time);
    if (s.size() < 2)
        s = "0" + s;
    
    stringstream ans;
    ans << h << ':' << m << ':' << s;
    
    return ans.str();
}