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

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        long long a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    // inputFileStream.close();
    return 0;
}