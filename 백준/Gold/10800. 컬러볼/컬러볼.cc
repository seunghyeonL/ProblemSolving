#include <bits/stdc++.h>
using namespace std;    

const int NMX = 200000;
const int SMX = 2000;
int N;

// 크기별 {색깔, 공 idx}들
vector<pair<int, int>> B_s[SMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int c, s;
        cin >> c >> s;
        B_s[s].emplace_back(c, i);
    }

    int acc = 0;
    vector<int> acc_c(N + 1);
    vector<int> ans(N);

    for (int s = 1; s <= SMX; s++)
    {
        for (auto &[c, i] : B_s[s])
            ans[i] = acc - acc_c[c];

        acc += s * B_s[s].size();
        for (auto &[c, i] : B_s[s])
            acc_c[c] += s;
    }

    for (int n : ans)
        cout << n << '\n';

    // inputFileStream.close();
    return 0;
}
