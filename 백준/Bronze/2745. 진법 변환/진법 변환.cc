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

    string str;
    cin >> str;

    int N;
    cin >> N;

    int ans = 0;
    for (char c : str)
    {
        ans *= N;

        int n;
        if (c >= '0' && c <= '9')
            n = c - '0';
        else
            n = 10 + (c - 'A');

        ans += n;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}