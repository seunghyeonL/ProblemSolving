#include <bits/stdc++.h>
using namespace std;

using P = pair<double, double>;
const double pi = 3.141592;

vector<double> D(8);
vector<P> pos(8);

double cross(const P &v1, const P &v2)
{
    /*
        (x1, y1) X (x2, y2)
        x1 * y2 - y1 * x2
    */

    const auto &[x1, y1] = v1;
    const auto &[x2, y2] = v2;

    return x1 * y2 - x2 * y1;
}

bool is_convex()
{
    for (int i = 0; i < 8; i++)
    {
        const P &a = pos[i];
        const P &b = pos[(i + 1) % 8];
        const P &c = pos[(i + 2) % 8];

        if (cross(a, b) + cross(b, c) + cross(c, a) < 0)
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    for (int i = 0; i < 8; i++)
        cin >> D[i];

    sort(D.begin(), D.end());

    vector<int> mask(8);
    iota(mask.begin(), mask.end(), 0);

    int ans = 0;
    do
    {
        // i : 배치할 각도
        // idx_D : 그때 D idx
        for (int i = 0; i < 8; i++)
        {
            int idx_D = mask[i];
            double x = D[idx_D] * cos(pi / 4 * i);
            double y = D[idx_D] * sin(pi / 4 * i);

            pos[i] = {x, y};
        }

        if (is_convex())
            ans++;

    } while (next_permutation(mask.begin(), mask.end()));

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}