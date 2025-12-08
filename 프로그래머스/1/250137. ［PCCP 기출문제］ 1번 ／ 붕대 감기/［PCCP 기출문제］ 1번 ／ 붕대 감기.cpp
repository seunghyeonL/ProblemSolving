#include <bits/stdc++.h>
using namespace std;

int t, x, y;
int ch, ct;
int mxh;

int dm[1001];

void get_damage(int d)
{
    ct = 1;
    ch -= d;
}

void recover()
{
    if (ct == t)
    {
        ch = min(ch + x + y, mxh);
        ct = 1;
    }
    else
    {
        ch = min(ch + x, mxh);
        ct++;
    }
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    t = bandage[0];
    x = bandage[1];
    y = bandage[2];
    ct = 1;
    ch = health;
    mxh = health;
    
    int et = 0;
    for (const auto& attack : attacks)
    {
        int at = attack[0];
        int d = attack[1];
        
        dm[at] = d;
        et = at;
    }
    
    int time = 1;
    bool is_dead = false;
    while (time <= et)
    {   
        if (dm[time]) get_damage(dm[time]);
        else recover();
        
        if (ch <= 0) 
        {
            is_dead = true;
            break;
        }
        
        time++;
    }
    
    return is_dead ? -1 : ch;
}