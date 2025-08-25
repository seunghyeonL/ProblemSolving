#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    using P = pair<int, int>;
    int answer = -1;
    int N = board.size();
    int M = board[0].size();
    const int INF = 1e9;

    /*
    홀수턴(내턴) 일 때는 내 위치, 짝수턴(상대) 일때는 상대 위치를 처리

    dfs(x1, y1, x2, y2, board, is1turn, is1win) : 이 상태이후로 게임이 끝나게
    되는 턴수

    이기는 쪽에서는 다음 위치의 dfs값이 최소인 쪽을 반환
    지는 쪽에서는 다음 위치의 dfs값이 최대인 쪽을 반환

    내가 이기는 경우, 내가 지는 경우 중 dfs 값이 더 작은 쪽이 답
    
    복잡해서 dfs를 두개로 나누자.
    */

    auto isValid = [&](int x, int y)
    { return x >= 0 && x < N && y >= 0 && y < M; };

    vector<P> moves{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    vector<P> loc{{aloc[0], aloc[1]}, {bloc[0], bloc[1]}};

    // 내가 이기는 최소 횟수
    // 이길수 없으면 INF이상의 값 반환
    function<int(bool)> win1Rec = [&](bool is1turn)
    {
        int cx, cy;

        if (is1turn)
        {
            cx = loc[0].first;
            cy = loc[0].second;

            if (board[cx][cy] == 0)
                return INF;
        }
        else
        {
            cx = loc[1].first;
            cy = loc[1].second;

            if (board[cx][cy] == 0)
                return 0;
        }

        int result = is1turn ? INF : 0;

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && board[nx][ny])
            {
                board[cx][cy] = 0;

                int nextRec{};
                if (is1turn)
                {
                    loc[0] = {nx, ny};
                    nextRec = win1Rec(!is1turn);
                    result = min(result, 1 + nextRec);
                    loc[0] = {cx, cy};
                }
                else
                {
                    loc[1] = {nx, ny};
                    nextRec = win1Rec(!is1turn);
                    result = max(result, 1 + nextRec);
                    loc[1] = {cx, cy};
                }

                board[cx][cy] = 1;
            }
        }

        return result;
    };

    // 상대가 이기는 최소 횟수
    // 이길 수 없으면 INF이상의 값 반환
    function<int(bool)> win2Rec = [&](bool is1turn)
    {
        int cx, cy;

        if (!is1turn)
        {
            cx = loc[1].first;
            cy = loc[1].second;

            if (board[cx][cy] == 0)
                return INF;
        }
        else
        {
            cx = loc[0].first;
            cy = loc[0].second;

            if (board[cx][cy] == 0)
                return 0;
        }

        int result = is1turn ? 0 : INF;

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && board[nx][ny])
            {
                board[cx][cy] = 0;

                int nextRec{};
                if (!is1turn)
                {
                    loc[1] = {nx, ny};
                    nextRec = win2Rec(!is1turn);
                    result = min(result, 1 + nextRec);
                    loc[1] = {cx, cy};
                }
                else
                {
                    loc[0] = {nx, ny};
                    nextRec = win2Rec(!is1turn);
                    result = max(result, 1 + nextRec);
                    loc[0] = {cx, cy};
                }

                board[cx][cy] = 1;
            }
        }

        return result;
    };

    int win1 = win1Rec(true);
    int win2 = win2Rec(true);

    return min(win1, win2);
}