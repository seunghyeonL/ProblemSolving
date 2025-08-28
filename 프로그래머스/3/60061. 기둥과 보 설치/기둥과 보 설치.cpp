#include <string>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    using T = tuple<int, int, int>; // x, y, 기둥보
    vector<vector<int>> answer;
    set<T> building;

    auto check = [&](int x, int y, int isBo)
    {
        if (isBo)
        {
            // 여기 아래가 기둥이거나
            // 오른쪽 아래가 기둥이거나
            // 양 옆에 보가 있거나
            return building.count({x, y - 1, 0}) ||
                   building.count({x + 1, y - 1, 0}) ||
                   (building.count({x - 1, y, 1}) &&
                    building.count({x + 1, y, 1}));
        }
        else
        {
            // 여기가 바닥이거나
            // 아래가 기둥이거나
            // 여기가 보 양쪽 중 하나거나
            return y == 0 || building.count({x, y - 1, 0}) ||
                   building.count({x - 1, y, 1}) || building.count({x, y, 1});
        }
    };

    for (auto command : build_frame)
    {
        int x = command[0];
        int y = command[1];
        int isBo = command[2];
        int isBuild = command[3];

        if (isBuild)
        {
            if (check(x, y, isBo))
                building.insert({x, y, isBo});
        }
        else
        {
            building.erase({x, y, isBo});
            bool isStable = true;

            if (isBo)
            {
                // 보를 빼면 왼쪽 보, 여기 기둥, 오른쪽 보, 오른쪽 기둥
                // 이 영향받는다.
                if (building.count({x - 1, y, 1}))
                    isStable &= check(x - 1, y, 1);

                if (building.count({x, y, 0}))
                    isStable &= check(x, y, 0);

                if (building.count({x + 1, y, 1}))
                    isStable &= check(x + 1, y, 1);

                if (building.count({x + 1, y, 0}))
                    isStable &= check(x + 1, y, 0);
            }
            else
            {
                // 기둥을 빼면 위쪽 보, 위쪽 왼쪽 보, 위쪽 기둥
                // 이 영향받는다.
                if (building.count({x, y + 1, 1}))
                    isStable &= check(x, y + 1, 1);

                if (building.count({x - 1, y + 1, 1}))
                    isStable &= check(x - 1, y + 1, 1);

                if (building.count({x, y + 1, 0}))
                    isStable &= check(x, y + 1, 0);
            }

            if (!isStable)
            {
                building.insert({x, y, isBo});
            }
        }
    }

    for (auto [x, y, isBo] : building)
    {
        answer.push_back({x, y, isBo});
    }

    return answer;
}
