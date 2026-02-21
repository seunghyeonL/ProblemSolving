#include <bits/stdc++.h>
using namespace std;

int N, M, L;
vector<int> D;

// q번 자를때 모든 조각을 mn_len 이상으로 만들 수 있는가?
// mn_len <= ans -> true
// mn_len > ans -> false
bool check(int mn_len, int q)
{
    int pn = 0;
    int cl = 0;

    for (int i = 0; i <= M; i++)
    {
        cl += D[i];

        if (cl >= mn_len)
        {
            pn++;
            cl = 0;
        }
    }

    if (pn >= q + 1)
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

    cin >> N >> M >> L;
    D.resize(M + 1);

    int prv = 0, cur = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> cur;
        D[i] = cur - prv;
        prv = cur;
    }

    D[M] = L - prv;

    for (int i = 0; i < N; i++)
    {
        int q;
        cin >> q;

        int l = 1;
        int r = L;
        while (l <= r)
        {
            int m = (l + r) / 2;

            if (check(m, q))
                l = m + 1;
            else
                r = m - 1;
        }

        cout << r << '\n';
    }
    // inputFileStream.close();
    return 0;
}
