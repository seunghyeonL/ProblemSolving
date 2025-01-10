#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int run(int health, const vector<vector<int>> &dungeons, vector<bool> isVisited,
        int cnt)
{
    // cout << "health: " << health << " " << "cnt: " << cnt << '\n';
    int result = cnt;

    auto it = find(isVisited.begin(), isVisited.end(), false);
    if (it == isVisited.end())
    {
        return result;
    }

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (isVisited[i])
        {
            continue;
        }

        if (health >= dungeons[i][0])
        {

            isVisited[i] = true;
            cnt++;
            health -= dungeons[i][1];

            // cout << "dungeon idx: " << i << '\n';

            int pickThisResult = run(health, dungeons, isVisited, cnt);
            result = pickThisResult > result ? pickThisResult : result;

            isVisited[i] = false;
            cnt--;
            health += dungeons[i][1];
        }
        else
        {
            isVisited[i] = true;
        }
    }

    // cout << result << endl;
    return result;
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> isVisited(dungeons.size(), false);

    return run(k, dungeons, isVisited, 0);
}