#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N, T;
int L[NMX];
int R[NMX];

bool check(int S)
{
    // 일단 최소치 만큼 주고
    // 남은 양을 배분 가능하면 true

    long long total = accumulate(L, L + N, 0);

    long long cap = 0;
    for (int i = 0; i < N; i++)
    {
        cap += min(S, R[i]) - L[i];
    }

    if (total + cap >= T)
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

    cin >> N >> T;
    
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
        cin >> R[i];
    }

    if (accumulate(L, L + N, 0) > T)
    {
        cout << -1;
        return 0;
    }

    int l = *max_element(L, L + N);
    int r = *max_element(R, R + N);

    while (l <= r)
    {
        int m = (l + r) / 2;

        // 지금 S로 가능하면 더 큰 S에서도 가능
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    if (l > *max_element(R, R + N))
        cout << -1;
    else
        cout << l;

    // inputFileStream.close();
    return 0;
}