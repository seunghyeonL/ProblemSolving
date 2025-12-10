#include <bits/stdc++.h>
using namespace std;

// 단순 시뮬레이션

const int NMX = 30;
int N, M;
bool destroyed[NMX][NMX];

// board를 시계 90도 회전변환
char e_board[NMX][NMX]; 

bool can_destroy(int x, int y)
{
    char a, b, c, d;
    a = e_board[x][y];
    b = e_board[x + 1][y];
    c = e_board[x][y + 1];
    d = e_board[x + 1][y + 1];
    
    return a == b && b == c && c == d;
}

int destroy()
{
    memset(destroyed, false, sizeof(destroyed));
    
    for (int i = 0 ; i < M - 1 ; i++)
        for (int j = 0 ; j < N - 1 ; j++)
        {
            if (e_board[i][j] == ' ') continue;
            if (can_destroy(i, j))
            {
                destroyed[i][j] = true;
                destroyed[i + 1][j] = true;
                destroyed[i][j + 1] = true;
                destroyed[i + 1][j + 1] = true;
            }
        }

    for (int i = 0 ; i < M ; i++)
    {
        vector<int> tmp;
        for (int j = 0 ; j < N ; j++)
        {
            if (!destroyed[i][j]) 
                tmp.push_back(e_board[i][j]);
        }
        
        copy(tmp.begin(), tmp.end(), e_board[i]);
        fill(e_board[i] + tmp.size(), e_board[i] + N, ' ');
    }
    
    int ret = 0;
    for (int i = 0 ; i < M ; i++)
        for (int j = 0 ; j < N ; j++)
        {
            if (destroyed[i][j]) ret++;
        }
    
    return ret;
}

int solution(int m, int n, vector<string> board) 
{
    N = m;
    M = n;
    memset(destroyed, false, sizeof(destroyed));
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            /*
                c -s 
                s  c
                
                0, 1
                -1, 0
                
                x = y
                y = N - 1 -x
            */
            e_board[j][N - 1 - i] = board[i][j];
        }
    
    /*
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < M ; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0 ; i < M ; i++)
    {
        for (int j = 0 ; j < N ; j++)
            cout << e_board[i][j] << ' ';
        cout << '\n';
    }
    */

    // ----
    
    int ans = 0;
    int dn = 0;
    do
    {
        dn = destroy();
        ans += dn;
    } while(dn > 0);
    
    return ans;
}