#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    using P = pair<int, int>;

    int answer = 0;
    int N = table.size();

    vector<P> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    vector<vector<int>> boardVisited(N, vector<int>(N, 0));
    vector<vector<int>> tableVisited(N, vector<int>(N, 0));

    multiset<vector<P>> blocks;

    auto isValid = [N](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    function<vector<P>(int, int)> makeBlock = [&](int x, int y)
    {
        vector<P> result;

        if (tableVisited[x][y] || !table[x][y])
            return result;

        tableVisited[x][y] = 1;
        result.push_back({x, y});

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (isValid(nx, ny) && !tableVisited[nx][ny] && table[nx][ny])
            {
                vector<P> nblock = makeBlock(nx, ny);
                result.insert(result.end(), nblock.begin(), nblock.end());
            }
        }

        return result;
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<P> block = makeBlock(i, j);
            if (!block.empty())
            {
                sort(block.begin(), block.end());
                auto [x0, y0] = block[0];

                // 첫 부분을 0, 0으로 정규화
                for (auto &[x, y] : block)
                {
                    x -= x0;
                    y -= y0;
                }
                blocks.insert(block);
            }
        }
    }

    function<vector<P>(int, int)> getPlace = [&](int x, int y)
    {
        vector<P> result;

        if (boardVisited[x][y] || game_board[x][y])
            return result;

        boardVisited[x][y] = 1;
        result.push_back({x, y});

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (isValid(nx, ny) && !boardVisited[nx][ny] && !game_board[nx][ny])
            {
                vector<P> nplace = getPlace(nx, ny);
                result.insert(result.end(), nplace.begin(), nplace.end());
            }
        }

        return result;
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<P> place = getPlace(i, j);
            if (!place.empty())
            {
                sort(place.begin(), place.end());
                auto [x0, y0] = place[0];

                // 첫 부분을 0, 0으로 정규화
                for (auto &[x, y] : place)
                {
                    x -= x0;
                    y -= y0;
                }

                auto it = blocks.find(place);
                if (it != blocks.end())
                {
                    answer += place.size();
                    blocks.erase(it);
                    continue;
                }

                // 90도 회전변환 세번
                for (int _ = 0; _ < 3; _++)
                {
                    for (auto &[x, y] : place)
                    {
                        tie(x, y) = make_pair(y, -x);
                    }
                    
                    // 정렬 후 다시 정규화
                    sort(place.begin(), place.end());
                    auto [x0, y0] = place[0];
                    
                    for (auto &[x, y] : place)
                    {
                        x -= x0;
                        y -= y0;
                    }

                    it = blocks.find(place);
                    if (it != blocks.end())
                    {
                        answer += place.size();
                        blocks.erase(it);
                        break;
                    }
                }
            }
        }
    }

    return answer;
}
