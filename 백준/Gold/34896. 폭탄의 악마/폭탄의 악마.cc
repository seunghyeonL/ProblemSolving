#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
int N, B;
vector<pair<int, int>> bomb;

// r반경으로 터뜨릴때 비용 B 이하로 모두 터뜨리는게 가능한가
// r >= ans => true
// r < ans => false
bool check(int range)
{
    int w = 0;

    for (int i = 0; i < N; i++)
    {
        auto [cx, cw] = bomb[i];

        // i 폭탄과 연쇄되는 폭탄 범위까지 i 늘리면서 최소 C[i]인 확인
        while (i + 1 < N)
        {
            auto [nx, nw] = bomb[i + 1];
            if (nx - cx <= range)
            {
                cx = nx;
                cw = min(cw, nw);
                i++;
            }
            else
                break;
        }

        w += cw;
        if (w > B)
            break;
    }

    if (w <= B)
        return true;
    else
        return false;
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
    bomb.resize(N);

    {
        vector<int> X(N);
        vector<int> C(N);

        for (int i = 0; i < N; i++)
            cin >> X[i];

        for (int i = 0; i < N; i++)
            cin >> C[i];

        for (int i = 0; i < N; i++)
        {
            bomb[i] = {X[i], C[i]};
        }

        cin >> B;
    }

    sort(bomb.begin(), bomb.end());

    int l = 1, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << '\n';

    // inputFileStream.close();
    return 0;
}