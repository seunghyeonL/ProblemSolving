#include <bits/stdc++.h>
using namespace std;

// 구조물 겹치게 설치하는 입력 x
// 없는 구조물 삭제 입력 x
// 벽면을 벗어나는 입력 x
// 바닥에 보 설치 입력 x

// 0 : 기둥, 1 : 보
// x, y입력을 뒤집어서 세로좌표를 x, 가로좌표를 y로 생각

const int NMX = 100;
int N;
bool pos_0[NMX + 1][NMX + 1]; // 기둥 위치
bool pos_1[NMX + 1][NMX + 1]; // 보 위치

bool is_stable(int x, int y)
{
    bool ret0 = true;
    
    // 기둥자리일때
    if (pos_0[x][y])
    {
        ret0 = false;
        // 바닥이거나 기둥 위이거나 이 자리가 보 양끝
        ret0 |= (x == 0);
        ret0 |= (x > 0 && pos_0[x - 1][y]);
        ret0 |= pos_1[x][y];
        ret0 |= (y > 0 && pos_1[x][y - 1]);
    }
    
    bool ret1 = true;
    // 보 자리일때
    if (pos_1[x][y])
    {
        // 양 끝중 하나가 기둥이거나 양끝이 보 (바닥인 경우는 없음)
        ret1 = false;
        ret1 |= pos_0[x - 1][y];
        ret1 |= (y < N && pos_0[x - 1][y + 1]);
        ret1 |= (y > 0 && pos_1[x][y - 1]) && (y < N && pos_1[x][y + 1]);
    }
    
    return ret0 && ret1;
}

// 짓고 제자리가 stable한지 체크
void build_0(int x, int y)
{
    pos_0[x][y] = true;
    
    bool ok = true;
    ok &= is_stable(x, y);
    
    if (!ok)
        pos_0[x][y] = false;
    
}

// 기둥을 삭제할때는 위쪽 자리, 위쪽 왼쪽 자리가 stable한지 체크
void remove_0(int x, int y)
{
    pos_0[x][y] = false;

    bool ok = true;
    ok &= is_stable(x + 1, y);
    ok &= (y == 0 || is_stable(x + 1, y - 1));
    
    if (!ok)
        pos_0[x][y] = true;
}

// 짓고 제자리가 stable한지 체크
void build_1(int x, int y)
{
    pos_1[x][y] = true;
    
    bool ok = true;
    ok &= is_stable(x, y);
    
    if (!ok)
        pos_1[x][y] = false;
}

// 보를 삭제할때는 제자리, 오른쪽, 왼쪽 자리가 stable 한지 체크
void remove_1(int x, int y)
{
    pos_1[x][y] = false;
    
    bool ok = true;
    ok &= is_stable(x, y);
    ok &= (y == 0 || is_stable(x, y - 1));
    ok &= (y == N || is_stable(x, y + 1));
    
    if (!ok)
        pos_1[x][y] = true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
    N = n;
    
    vector<vector<int>> answer;
    
    for (const auto& command : build_frame)
    {
        // x, y 뒤집기
        int y = command[0];
        int x = command[1];
        int a = command[2];
        int t = command[3];
        
        if (a == 0 && t == 0)
            remove_0(x, y);
        else if (a == 0 && t == 1)
            build_0(x, y);
        if (a == 1 && t == 0)
            remove_1(x, y);
        else if (a == 1 && t == 1)
            build_1(x, y);
        
        // cout << x << ' ' << y << ' ' << a << ' ' << t << '\n';
        // cout << pos_0[x][y] << ' ' << pos_1[x][y] << '\n';
        
    }
    
    for (int x = 0 ; x <= N ; x++)
    {
        for (int y = 0 ; y <= N ; y++)
        {
            if (pos_0[x][y]) 
                answer.push_back({y, x, 0});
            
            if (pos_1[x][y])
                answer.push_back({y, x, 1});
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}