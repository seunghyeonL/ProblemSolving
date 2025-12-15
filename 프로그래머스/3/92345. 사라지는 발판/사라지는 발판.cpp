#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

// mini_max, dfs
// 입력이 작아 memo는 x
// 다음 게임 결과 중 상대의 승리가 하나라도 있으면 그 중 가장 늦게 끝나는 쪽으로 반환
// 다음 게임 결과 중 상대가 모두 패배하면 그 중 가장 빨리 끝나는 쪽으로 반환 

const int MX = 5;
int N, M;

vector<vector<int>> board;
int used[MX][MX];

// 선공 : 0, 후공 : 1
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

// 승리 여부, 남은 턴수
P dfs(int turn)
{   
    auto& [cx, cy] = pos[turn % 2];
    
    if (used[cx][cy]) // 패배
        return {0, 0};
    
    vector<P> next_results;
    
    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;
        
        if (!is_valid(nx, ny) || !board[nx][ny] || used[nx][ny])
            continue;
        
        used[cx][cy] = true;
        cx += dx;
        cy += dy;
        
        next_results.push_back(dfs(turn + 1));
        
        cx -= dx;
        cy -= dy;
        used[cx][cy] = false;
    }
    
    // 패배
    if (next_results.empty())
        return {0, 0};
    
    bool can_win = false;
    for (auto [is_win, rt] : next_results)
    {
        if (!is_win) // 상대의 패배
        {
            can_win = true;
            break;
        }
    }
    
    if (can_win)
    {
        // 가장 빨리 끝나게
        int c_rt = 25;
        for (auto [is_win, rt] : next_results)
        {
            if (!is_win)
                c_rt = min(c_rt, rt + 1);
        }
        
        return {1, c_rt};
    }
    else
    {
        // 상대가 모두 승리
        // 가장 늦게 끝나게
        int c_rt = 0;
        for (auto [is_win, rt] : next_results)
        {
            c_rt = max(c_rt, rt + 1);
        }
        
        return {0, c_rt};
    }
}

int solution(vector<vector<int>> _board, vector<int> aloc, vector<int> bloc) 
{
    board = _board;
    N = board.size();
    M = board[0].size();
    memset(used, 0, sizeof(used));
    
    pos[0] = {aloc[0], aloc[1]};
    pos[1] = {bloc[0], bloc[1]};
    
    return dfs(0).second;
}