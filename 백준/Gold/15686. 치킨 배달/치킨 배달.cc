#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        치킨집 M개 고르고 거리 합 최소 구하기
    */

    using P = pair<int, int>;

    int N, M;
    cin >> N >> M;

    vector<P> houses;
    vector<P> chickens;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            cin >> val;

            if (val == 1)
            {
                houses.emplace_back(i, j);
            }
            else if (val == 2)
            {
                chickens.emplace_back(i, j);
            }
        }
    }

    int csize = chickens.size();
    int hsize = houses.size();

    vector<bool> mask(csize);
    fill(mask.begin(), mask.begin() + M, true);

    int res = 1e9;

    do
    {
        // 이 combination에서의 도시 치킨 거리
        int cdd = 0;
        for (auto [hx, hy] : houses)
        {
            // 이 집의 치킨 거리
            int mn = 1e9;
            for (int i = 0; i < csize; i++)
            {
                if (!mask[i])
                    continue;

                auto [cx, cy] = chickens[i];

                mn = min(mn, abs(cx - hx) + abs(cy - hy));
            }
            cdd += mn;
        }
        res = min(res, cdd);
    } while (prev_permutation(mask.begin(), mask.end()));

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
