#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
bool dp[NMX + 1]; // N개로 시작할때 선공의 승리 여부

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    /*
        상대가 패배하는 수를 하나라도 만들 수 있으면 승리
    */

    for (int i = 5; i <= N; i++)
    {
        bool win = false;
        for (int n : {1, 3, 4})
        {
            if (!dp[i - n])
            {
                win = true;
                break;
            }
        }

        dp[i] = win;
    }

    cout << (dp[N] ? "SK" : "CY");

    // inputFileStream.close();
    return 0;
}