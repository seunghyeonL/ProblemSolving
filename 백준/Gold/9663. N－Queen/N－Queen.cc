#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        백트래킹
        각 행의 가능한 부분에 배치
        마지막 행에 배치되면 cnt증가
    */

    int N;
    cin >> N;

    vector<bool> col(N);
    vector<bool> diag1(2 * N); // x + y = c [0, 2 * N)
    vector<bool> diag2(2 * N); // x - y + N = c [0, 2 * N)

    int cnt = 0;
    function<void(int)> setQueen = [&](int x)
    {
        if (x == N)
        {
            cnt++;
            return;
        }

        for (int y = 0; y < N; y++)
        {
            if (col[y] || diag1[x + y] || diag2[x - y + N])
                continue;

            col[y] = diag1[x + y] = diag2[x - y + N] = true;
            setQueen(x + 1);
            col[y] = diag1[x + y] = diag2[x - y + N] = false;
        }
    };

    setQueen(0);

    cout << cnt << '\n';

    // inputFileStream.close();
    return 0;
}
