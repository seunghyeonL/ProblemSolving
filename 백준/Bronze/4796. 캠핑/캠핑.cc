#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, P, V;
    int t = 0;
    while (cin >> L >> P >> V)
    {
        if (L == 0)
            break;
        t++;

        int answer = 0;

        answer += V / P * L;
        answer += min(V % P, L);
        cout << "Case " << t << ": " << answer << '\n';
    }

    // ifstream inputFileStream("input.txt");

    // inputFileStream.close();
    return 0;
}