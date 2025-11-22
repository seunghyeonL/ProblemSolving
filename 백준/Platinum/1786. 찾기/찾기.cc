#include <bits/stdc++.h>
using namespace std;

const int SZMX = 1000000;
string T, P;
int F[SZMX]; // P 실패함수

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
ABC ABCDAB ABCDABCDABDE ABCDABCDABDE
ABCDABD
    */

    getline(cin, T);
    getline(cin, P);

    int n = T.size();
    int m = P.size();

    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && P[i] != P[j])
            j = F[j - 1];

        if (P[i] == P[j])
            F[i] = ++j;
    }

    int ans = 0;
    vector<int> history;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && T[i] != P[j])
            j = F[j - 1];

        if (T[i] == P[j])
            j++;

        if (j == m)
        {
            ans++;
            history.push_back(i + 1 - m + 1);
            j = F[j - 1];
        }
    }

    cout << ans << '\n';
    for (int h : history)
    {
        cout << h << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}