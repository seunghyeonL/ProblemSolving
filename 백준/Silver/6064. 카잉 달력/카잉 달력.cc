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

    /*
        M == 3, N == 5

        1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
        1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5

        K 가 x, y로 나타난다면
        K == x mod M
        K == y mod N
    */

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        y %= N;

        int k = x;
        int res = -1;
        while (k <= M * N)
        {
            if (k % N == y)
            {
                res = k;
                break;
            }

            k += M;
        }

        cout << res << '\n';
    }

    // inputFileStream.close();
    return 0;
}