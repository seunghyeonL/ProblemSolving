#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int N, M;
int used[5][5];

P pos[2];

vector<P> moves
{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

// 내 턴에 움직일 수 있는 모든 경우에 대해 다음턴에 상대가 지는경우가 있으면 그 중 가장 끝나는 시간이 빠른 케이스로
// 다음턴에 상대가 지는 경우가 없으면 그 중 가장 끝나는 시간이 느린 케이스로

// 승리 여부, 남은 이동 횟수
P dfs(int ct, const vector<vector<int>>& board)
{   
    int pn = ct % 2;
    auto& [cx, cy] = pos[pn];
    
    if (used[cx][cy]) // 패배, 종료
    {
        return {0, 0};
    }
    
    vector<P> next_results;
    
    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;
        
        if (is_valid(nx, ny) && board[nx][ny] && !used[nx][ny])
        {
            int px = cx;
            int py = cy;
            
            used[cx][cy] = true;
            cx = nx;
            cy = ny;
            
            next_results.push_back(dfs(ct + 1, board));
            
            cx = px;
            cy = py;
            used[cx][cy] = false;
        }
    }

    if (next_results.size() == 0) // 패배, 종료
    {
        return {0, 0};
    }
    
    bool can_win = false;
    for (auto [is_win, r_cnt] : next_results)
    {
        if (!is_win)
        {
            can_win = true;
            break;   
        }
    }
    
    if (can_win) // 다음 턴 상대가 지는 경우가 있음 => 이번턴 내 승리
    {
        int c_r_cnt = 25;
        for (auto [is_win, r_cnt] : next_results)
        {
            if (!is_win)
            {
                c_r_cnt = min(c_r_cnt, r_cnt);
            }
        }
        return {1, c_r_cnt + 1};
    }
    else // 다음 턴 상대가 지는 경우가 없음 => 이번턴 내 패배
    {
        int c_r_cnt = 0;
        for (auto [is_win, r_cnt] : next_results)
        {
            c_r_cnt = max(c_r_cnt, r_cnt);
        }
        return {0, c_r_cnt + 1};
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size();
    M = board[0].size();
    
    pos[0].first = aloc[0];
    pos[0].second = aloc[1];
    pos[1].first = bloc[0];
    pos[1].second = bloc[1];
    
    return dfs(0, board).second;
}