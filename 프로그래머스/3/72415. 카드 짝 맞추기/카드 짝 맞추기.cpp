#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;

const int INF = 1e9;
const int N = 4;
set<int> card_set;
vector<pair<int, int>> card_pos[7];

bool is_card[N][N];

// cost[sx][sy][ex][ey] : {sx, sy} -> {ex, ey} 최소 조작 횟수 
int cost[N][N][N][N];

vector<pair<int, int>> moves
{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void init_cost(int sx, int sy)
{
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            cost[sx][sy][i][j] = INF;
}

void dijkstra(int sx, int sy)
{
    init_cost(sx, sy);
    
    auto* c_cost = cost[sx][sy];
    
    priority_queue<T, vector<T>, greater<T>> pq;
    
    c_cost[sx][sy] = 0;
    pq.emplace(0, sx, sy);
    
    while (!pq.empty())
    {
        auto [d, cx, cy] = pq.top();
        pq.pop();
        
        if (d > c_cost[cx][cy]) continue;
        
        for (auto [dx, dy] : moves)
        {
            int nx1 = cx + dx;
            int ny1 = cy + dy;

            if (is_valid(nx1, ny1) && c_cost[nx1][ny1] > d + 1)
            {
                c_cost[nx1][ny1] = d + 1;
                pq.emplace(d + 1, nx1, ny1);
            }
            
            int nx2 = nx1;
            int ny2 = ny1;
            
            while (is_valid(nx2 + dx, ny2 + dy) && !is_card[nx2][ny2])
            {
                nx2 += dx;
                ny2 += dy;
            }
            
            if (is_valid(nx2, ny2) && c_cost[nx2][ny2] > d + 1)
            {
                c_cost[nx2][ny2] = d + 1;
                pq.emplace(d + 1, nx2, ny2);
            }
        }
    }
}

// board 상태, 커서 위치 cx, cy 일때 다 없애기까지 필요한 최소 조작 수
int dfs(int cx, int cy)
{
    // 어떤 카드를 없앨지 고르고 
    // 없앤 상태로 dfs 돌리고
    // 돌린 dfs 값과 고른 카드 없애는 비용 더해서 
    // 최솟값 반환
    
    if (card_set.empty()) 
    {
        return 0;
    }
    
    dijkstra(cx, cy);
    
    int ret = INF;
    
    for (int card : card_set)
    {
        auto [tx1, ty1] = card_pos[card][0];
        auto [tx2, ty2] = card_pos[card][1];
        
        dijkstra(tx1, ty1);
        dijkstra(tx2, ty2);
        
        // 엔터 두번
        int path_cost1 = cost[cx][cy][tx1][ty1] + cost[tx1][ty1][tx2][ty2] + 2;
        int path_cost2 = cost[cx][cy][tx2][ty2] + cost[tx2][ty2][tx1][ty1] + 2;
        
        is_card[tx1][ty1] = false;        
        is_card[tx2][ty2] = false;
        card_set.erase(card);
        
        ret = min(ret, dfs(tx1, ty1) + path_cost2);
        ret = min(ret, dfs(tx2, ty2) + path_cost1);
        
        card_set.insert(card);
        is_card[tx1][ty1] = true;        
        is_card[tx2][ty2] = true;
    }
    
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
        {
            if (!board[i][j]) continue;
            is_card[i][j] = true;
            
            card_set.insert(board[i][j]);
            card_pos[board[i][j]].emplace_back(i, j);
        }
    
    return dfs(r, c);
}