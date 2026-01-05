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

    const int MX = 100;
    int N, M;
    cin >> N >> M;

    multiset<int> ms; // 로봇마다 마지막 정리한 열 idx
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int n;
            cin >> n;

            if (n == 1)
            {
                auto ub = ms.upper_bound(j);

                if (ub != ms.begin())
                    ms.erase(prev(ub));

                ms.insert(j);
            }
        }

    cout << ms.size();

    // inputFileStream.close();
    return 0;
}