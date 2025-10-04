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
        0덩어리개수, 1덩어리 개수 중 작은것이 정답
     */

    string str;
    cin >> str;

    vector<int> cnt(2, 0);
    int cur = -1;

    for (char c : str)
    {
        if (c - '0' != cur)
        {
            cur = c - '0';
            cnt[c - '0']++;
        }
    }

    cout << min(cnt[0], cnt[1]) << '\n';

    // inputFileStream.close();
    return 0;
}
