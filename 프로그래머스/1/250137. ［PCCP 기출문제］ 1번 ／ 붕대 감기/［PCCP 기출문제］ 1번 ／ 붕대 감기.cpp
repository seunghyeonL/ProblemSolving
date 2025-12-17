#include <bits/stdc++.h>
using namespace std;

int bt, bx, by;
int ct, ch, mh;
int et;

void heal()
{
    if (++ct == bt)
    {
        ch = min(mh, ch + bx + by);
        ct = 0;
    }
    else
        ch = min(mh, ch + bx);
}

void apply_damage(int dm)
{
    ch = max(0, ch - dm);
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    bt = bandage[0];
    bx = bandage[1];
    by = bandage[2];
    
    ct = 0;
    mh = health;
    ch = mh;
    
    et = attacks.back()[0];
    
    int t = 0;
    int a_idx = 0;
    bool dead = false;
    
    while (++t <= et)
    {
        if (attacks[a_idx][0] == t)
        {
            apply_damage(attacks[a_idx++][1]);        
            ct = 0;
        }
        else
            heal();
        
        if (ch == 0)
        {
            dead = true;
            break;
        }
    }
    
    return dead ? -1 : ch;
}