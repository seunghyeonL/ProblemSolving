#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
int N;

vector<pair<int, int>> B; // 공 idx별 {크기, 색깔}
// 공 크기, 색별 공 사이즈 카운팅하기

unordered_map<int, int> S_cnt;            // 공 크기 개수 카운팅
unordered_map<int, int> S_c_cnt[NMX + 1]; // 색깔별 공 크기 개수 카운팅

vector<int> S;            // 공 크기 모음
vector<int> S_c[NMX + 1]; // 색깔별 공 크기 모음

vector<int> W;            // 공 크기별 자기보다 작은 크기 합
vector<int> W_c[NMX + 1]; // 색깔별 W

// 크기별로 색 상관없이 자기 크기보다 작은 공 합
// 색별로 자기 크기보다 작은 공 합 미리 구해놓고 쿼리하기

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;
    B.resize(N);
    S.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int c, s;
        cin >> c >> s;

        B[i] = {s, c};

        S.push_back(s);
        S_c[c].push_back(s);

        S_cnt[s]++;
        S_c_cnt[c][s]++;
    }

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    for (int c = 1; c <= N; c++)
    {
        if (S_c[c].empty())
            continue;

        sort(S_c[c].begin(), S_c[c].end());
        S_c[c].erase(unique(S_c[c].begin(), S_c[c].end()), S_c[c].end());
    }

    {
        int sz = S.size();
        W.resize(sz + 1);
        W[0] = 0;

        for (int i = 1; i <= sz; i++)
        {
            int s = S[i - 1];
            W[i] = W[i - 1] + s * S_cnt[s];
        }
    }

    for (int c = 1; c <= N; c++)
    {
        int sz = S_c[c].size();
        W_c[c].resize(sz + 1);
        W_c[c][0] = 0;

        for (int i = 1; i <= sz; i++)
        {
            int s = S_c[c][i - 1];
            W_c[c][i] = W_c[c][i - 1] + s * S_c_cnt[c][s];
        }
    }

    for (int i = 0; i < N; i++)
    {
        const auto &[s, c] = B[i];

        int lbi_S = lower_bound(S.begin(), S.end(), s) - S.begin();
        int lbi_S_c =
            lower_bound(S_c[c].begin(), S_c[c].end(), s) - S_c[c].begin();

        cout << W[lbi_S] - W_c[c][lbi_S_c] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
