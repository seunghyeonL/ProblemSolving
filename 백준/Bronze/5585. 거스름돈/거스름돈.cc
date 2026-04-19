#include <bits/stdc++.h>
using namespace std;

/*
    모든 동전이 그보다 더 작은 동전의 배수로 나타낼 수 있기 때문에
    가장 큰 동전을 최대한 많이 주는 방향으로
*/

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
    N = 1000 - N;

    vector<int> coins{500, 100, 50, 10, 5, 1};

    int ans = 0;
    for (int coin : coins)
    {
        ans += N / coin;
        N %= coin;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
