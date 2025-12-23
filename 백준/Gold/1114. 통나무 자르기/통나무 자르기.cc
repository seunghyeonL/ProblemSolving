#include <bits/stdc++.h>
using namespace std;

int L, K, C;
int N;         // D 길이
vector<int> D; // 자를 수 있는 부분을 다 잘랐을때 구간 길이들

// mx_len >= ans 이면 모든 구간이 mx_len이하가 되도록 합쳤을때 개수가 C + 1
// 이하 -> 가능
// max D <= mx_len < ans 이면 모든 구간이 mx_len이하가 되도록 합쳤을때
// 개수가 C + 1 이상 -> 불가능

bool check(int mx_len)
{
    int p_cnt = 1;
    int cl = 0;

    for (int i = 0; i < N; i++)
    {
        if (cl + D[i] <= mx_len)
        {
            cl += D[i];
            continue;
        }

        // cl + D[i] > mx_len
        p_cnt++;
        cl = D[i];
    }

    if (p_cnt <= C + 1)
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

    // 가운데 있을수록 더 많이 더해짐

    cin >> L >> K >> C;

    {
        vector<int> cut_pos(K);
        for (int i = 0; i < K; i++)
            cin >> cut_pos[i];

        sort(cut_pos.begin(), cut_pos.end());
        cut_pos.erase(unique(cut_pos.begin(), cut_pos.end()), cut_pos.end());

        int px = 0;
        for (int i = 0; i < cut_pos.size(); i++)
        {
            int cx = cut_pos[i];
            D.push_back(cx - px);
            px = cx;
        }

        D.push_back(L - px);
    }

    N = D.size();

    int l = *max_element(D.begin(), D.end()), r = L;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    int ans = l;
    cout << ans << ' ';

    int x = L; // 뒤에서부터 제일 크게 자른 지점
    int cl = 0;
    int cut_cnt = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (cl + D[i] <= ans)
        {
            cl += D[i];
            continue;
        }

        // x - D[i] > ans
        x -= cl;
        cl = D[i];
        cut_cnt++;
    }

    if (cut_cnt < C)
        x = D[0];

    cout << x << '\n';

    // inputFileStream.close();
    return 0;
}