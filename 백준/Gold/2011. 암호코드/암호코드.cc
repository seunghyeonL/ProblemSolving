#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
const int NMX = 5000;
string str;
int dp[NMX + 1]; // dp[i] : i번째 글자까지 봤을때 해석 가짓수

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> str;
    int N = str.size();

    // dp[i] = (str[i] != '0' ? dp[i - 1] : 0) + (str[i - 1] != '0' && 1 <= stoi(str[i - 1, i]) <= 26 ? dp[i - 2] : 0)
    // 0이 두개 이상 연속하거나 첫글자가 0이면 실패

    bool prevZero = true;
    for (char c : str)
    {
        if (prevZero && c == '0')
        {
            cout << 0;
            return 0;
        }

        if (c == '0')
        {
            prevZero = true;
        }
        else
        {
            prevZero = false;
        }
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] += str[i - 1] != '0' ? dp[i - 1] : 0;
        dp[i] %= MOD;

        int d = stoi(str.substr(i - 2, 2));

        dp[i] += (str[i - 2] != '0' && 1 <= d && d <= 26) ? dp[i - 2] : 0;
        dp[i] %= MOD;
    }

    cout << dp[N];

    // inputFileStream.close();
    return 0;
}