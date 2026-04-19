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
        N이 몇번째 껍데기에 있는가?
    */

    int N;
    cin >> N;

    int ans = 1;

    for (int i = 1; N > 1; i++)
    {
        N -= i * 6;
        ans++;
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}