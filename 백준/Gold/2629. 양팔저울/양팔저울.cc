#include <bits/stdc++.h>
using namespace std;

const int NMX = 30;
int N;
vector<int> W;

int T;

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

    cin >> N;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        W.push_back(w);
        W.push_back(w);

        sum += w;
    }

    vector<bool> dp(sum * 2 + 1);
    dp[0] = true;

    for (int w : W)
    {
        for (int i = sum * 2; i >= w; i--)
        {
            dp[i] = dp[i] || dp[i - w];
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int t;
        cin >> t;
        
        if (t > sum) 
        {
            cout << 'N' << ' ';
            continue;
        }
        
        cout << (dp[sum + t] ? 'Y' : 'N') << ' ';
    }
    cout << '\n';

    // for (int el : dp)
    // {
    //     cout << el << ' ';
    // }
    // cout << '\n';

    // inputFileStream.close();
    return 0;
}