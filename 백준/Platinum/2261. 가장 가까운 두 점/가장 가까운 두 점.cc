#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

const int NMX = 100000;
int N;
// pair<int, int> arr[NMX];
vector<P> pos;

int square(int x)
{
    return x * x;
}

int get_dist(int x1, int y1, int x2, int y2)
{
    return square(x2 - x1) + square(y2 - y1);
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    pos.resize(N);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        pos[i] = {x, y};
    }

    sort(pos.begin(), pos.end());

    // set이 중복 제거할거라 미리 동일 점 체크
    for (int i = 0; i < N - 1; i++)
    {
        if (pos[i] == pos[i + 1])
        {
            cout << 0 << '\n';
            return 0;
        }
    }

    int mn_d = get_dist(10000, 10000, -10000, -10000);

    auto compare = [](const P &a, const P &b)
    {
        const auto &[ax, ay] = a;
        const auto &[bx, by] = b;

        return ay == by ? ax < bx : ay < by;
    };

    // 현재까지 본 점 중 가능 후보군
    set<P, decltype(compare)> cand(compare);

    // events 벡터의 인덱스
    // cand에서 빠르게 삭제하기 위함
    int li = 0;

    for (int i = 0; i < N; i++)
    {
        auto [x1, y1] = pos[i];

        // 너무 x가 벌어진 점 삭제
        while (li < i)
        {
            auto [x2, y2] = pos[li];
            if (square(x2 - x1) < mn_d)
                break;

            cand.erase(pos[li++]);
        }

        // (y2 - y1)^2 < mn_d
        // y2 > y1 - sqrt(mn_d) && y2 < y1 + sqrt(mn_d)
        // 소수점 오차때문에 범위를 넉넉하게 ceil
        int offset = ceil(sqrt(mn_d));
        auto lbi = cand.lower_bound({-50000, y1 - offset});
        auto ubi = cand.upper_bound({50000, y1 + offset});

        for (auto it = lbi; it != ubi; ++it)
        {
            int x2 = it->first;
            int y2 = it->second;

            int d = get_dist(x1, y1, x2, y2);
            mn_d = min(mn_d, d);
        }

        cand.emplace(x1, y1);
    }

    cout << mn_d;

    // inputFileStream.close();
    return 0;
}