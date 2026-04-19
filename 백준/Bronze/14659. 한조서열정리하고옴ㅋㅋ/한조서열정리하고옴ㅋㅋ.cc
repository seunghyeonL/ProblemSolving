#include <bits/stdc++.h>
using namespace std;

const int NMX = 30000;
int N;
int H[NMX];

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
    for (int i = 0; i < N; i++)
        cin >> H[i];

    int mx = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int cnt = 0;

        for (int j = i + 1 ; j < N ; j++)
        {
            if (H[j] < H[i]) cnt++;
            else break;
        }
        
        mx = max(mx, cnt);
    }

    cout << mx;

    // inputFileStream.close();
    return 0;
}