#include <bits/stdc++.h>
using namespace std;

int M, N;

vector<vector<int>> locker;
vector<vector<int>> keys[4];

bool check()
{
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            if (locker[i][j] != 1) 
                return false;
    
    return true;
}

bool solution(vector<vector<int>> _key, vector<vector<int>> _lock) 
{
    M = _key.size();
    N = _lock.size();
    
    fill(keys, keys + 4, vector<vector<int>>(M, vector<int>(M)));
    
    keys[0] = _key;
    locker = _lock;

    /*
    c -s
    s  c
    
    0 -1
    1  0
    
    x' = M - 1 - y
    y' = x
    */
    
    // rotate
    for (int r = 1 ; r <= 3 ; r++)
    {
        for (int i = 0 ; i < M ; i++)
            for (int j = 0 ; j < M ; j++)
                keys[r][M - 1 - j][i] = keys[r - 1][i][j];
    }
    
    for (int r = 0 ; r < 4 ; r++)
    {
        const auto& cur_key = keys[r];
        
        // i, j범위 : [0 - (M - 1), N - 1 + M - 1]
        
        for (int si = -(M - 1) ; si < N ; si++)
        {
            for (int sj = -(M - 1) ; sj < N ; sj++)
            {
                for (int i = 0 ; i < M ; i++)
                {
                    for (int j = 0 ; j < M ; j++)
                    {
                        int x = si + i;
                        int y = sj + j;
                        
                        if (x < 0 || x >= N) continue;
                        if (y < 0 || y >= N) continue;
                        
                        locker[x][y] += keys[r][i][j];
                    }
                }
                
                if (check())
                    return true;
                
                locker = _lock;
            }
        }
    }
    
    return false;
}