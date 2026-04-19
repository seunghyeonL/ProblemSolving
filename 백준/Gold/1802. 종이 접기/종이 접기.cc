#include <bits/stdc++.h>
using namespace std;

// 중앙값을 기점으로 양쪽이 반대여야함

string str;

bool DnC(int l, int r)
{
    if (l == r)
        return true;

    int m = (l + r) / 2;

    bool ret = true;
    for (int d = 1; m + d <= r; d++)
    {
        if (str[m - d] == str[m + d])
        {
            ret = false;
            break;
        }
    }

    return ret && DnC(l, m - 1) && DnC(m + 1, r);
}

void solve()
{
    cin >> str;

    cout << (DnC(0, str.size() - 1) ? "YES" : "NO") << '\n';
}

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

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}