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

    int N, M, K;
    cin >> N >> M >> K;

    if (!(M - 1 + K <= N && N <= M * K))
    {
        cout << -1;
        return 0;
    }

    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);

    vector<int> blocks(M);
    blocks[0] = K;
    if (M > 1)
    {
        fill(blocks.begin() + 1, blocks.end(), (N - K) / (M - 1));
        for (int i = 1, r = (N - K) % (M - 1); r > 0; i++, r--)
            blocks[i]++;
    }

    for (int i = 0, x = 0; i < M; i++)
    {
        int len = blocks[i];
        reverse(arr.begin() + x, arr.begin() + x + len);
        x += len;
    }

    for (int n : arr)
        cout << n << ' ';

    // inputFileStream.close();
    return 0;
}