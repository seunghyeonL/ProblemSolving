#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 각 고음 구성음을 가장 먼저 낸 사람을 고르는게 최적
    // 입력받으면서 현재 고음 체크

    int N, A, D;
    cin >> N >> A >> D;

    int ans = 0;
    int cur = A;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (cur == n)
        {
            ans++;
            cur += D;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
