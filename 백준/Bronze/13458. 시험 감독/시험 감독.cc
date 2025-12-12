#include <bits/stdc++.h>
using namespace std;

const int NMX = 1'000'000;
int N;
vector<int> A;
int B, C;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> B >> C;

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        int m = 0;    // 감독관 수;
        int n = A[i]; // 시험보는 인원

        m++;
        n -= B;

        if (n > 0)
        {
            m += (n + C - 1) / C;
        }

        ans += m;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
