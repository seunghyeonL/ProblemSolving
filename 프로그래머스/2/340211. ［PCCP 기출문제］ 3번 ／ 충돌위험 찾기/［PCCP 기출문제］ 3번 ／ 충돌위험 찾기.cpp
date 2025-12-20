#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// 각 로봇이 인접한 칸으로 이동 가능
// 운송 포인트 경로가 있고 각 로봇이 그 경로로 이동
// 동시에 같은 칸에 로봇이 두대 이상 있으면 충돌 상황
// 행이동 먼저, 그 다음 열이동

// route에 1 base point idx를 0 base로 변환

// 단순 시뮬레이션
// 좌표 : 1 base
// 운송 포인트 : 1 base
// 로봇 번호 : 0 base

const int LMT = 100;

vector<P> robot_pos;
vector<int> robot_route_idx; // 로봇이 목표로 이동중인 point idx
vector<P> points;
vector<vector<int>> routes;
int board[LMT + 1][LMT + 1];

int N; // 운송 포인트 수
int M; // route 마다 운송 포인트 수
int R; // 로봇 수

int end_cnt; // 이동이 끝난 로봇 수

// 충돌 개수 체크
int check()
{
    int ret = 0;
    for (int i = 1 ; i <= LMT ; i++)
        for (int j = 1 ; j <= LMT ; j++)
            if (board[i][j] > 1)
                ret++;
    
    return ret;
}

// 충돌 체크하고 로봇을 한칸씩 이동
void simulate(int& cnt)
{
    cnt += check();
    
    for (int ri = 0 ; ri < R ; ri++)
    {
        auto& [crx, cry] = robot_pos[ri];
        int& rri = robot_route_idx[ri]; 
        
        // 작업 끝난 상태
        if (rri == M + 1)
            continue;
        
        // 목표지점 도달; 로봇 없애기
        if (rri == M)
        {
            board[crx][cry]--;
            rri++;
            end_cnt++;
            continue;
        }
        
        // 이동중인 목표지점 포인트 
        int pi = routes[ri][rri];
        
        auto [px, py] = points[pi];
        
        if (crx != px) // 행이 다르면 그 행으로 한칸 이동
        {
            board[crx][cry]--;
            crx += (px - crx) / abs(px - crx);
            board[crx][cry]++;
        }
        else if (cry != py) // 행이 같고 열이 다르면 그 열로 한칸 이동
        {
            board[crx][cry]--;
            cry += (py - cry) / abs(py - cry);
            board[crx][cry]++;
        }
        
        // 이동 후 목표지점 도달했으면 목표지점 갱신
        if (crx == px && cry == py)
            rri++;
    }
}

int solution(vector<vector<int>> _points, vector<vector<int>> _routes) 
{
    N = _points.size();
    R = _routes.size();
    M = _routes[0].size();
    end_cnt = 0;
    
    robot_pos.resize(R); // 0 base
    points.resize(N); // 0 base
    robot_route_idx.resize(R);
    routes = _routes;
    
    for (int i = 0 ; i < N ; i++)
    {
        const auto& point = _points[i];
        int x = point[0];
        int y = point[1];
        
        points[i] = {x, y};
    }
    
    // point idx를 0 base로
    for (auto& r : routes)
        for (auto& el : r)
            el--;
    
    for (int i = 0 ; i < R ; i++)
        robot_route_idx[i] = 1; // 두번째 지점이 초기 목표 지점
    
    memset(board, 0, sizeof(board));
    
    for (int i = 0 ; i < R ; i++)
    {
        int pi = routes[i][0]; // 첫 운송 포인트
        robot_pos[i] = points[pi];
        
        auto [sx, sy] = points[pi];
        board[sx][sy]++;
    }
    
//     for (auto [x, y] : points)
//     {
//         cout << x << ' ' << y << '\n';
//     }
//     cout << '\n';
    
//     for (auto& r : routes)
//     {
//         for (auto& el : r)
//             cout << el << ' ';
//         cout << '\n';
//     }
    
    // for (auto [x, y] : robot_pos)
    // {
    //     cout << x << ' ' << y << '\n';
    // }
    // cout << '\n';
    
    // ---
    
    int ans = 0;
    while (end_cnt < R)
        simulate(ans);
    
    return ans;
}