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

    int N, K;
    cin >> N >> K;

    bool found = false;
    for (int i = 1, cnt = 0; i <= N; i++)
    {
        if (N % i == 0)
            cnt++;

        if (cnt == K)
        {
            found = true;
            cout << i;
            break;
        }
    }

    if (!found)
        cout << 0;

    // inputFileStream.close();
    return 0;
}