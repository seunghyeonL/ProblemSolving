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

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    ++N, ++M;

    cout << (H / N + (H % N ? 1 : 0)) * (W / M + (W % M ? 1 : 0));

    // inputFileStream.close();
    return 0;
}
