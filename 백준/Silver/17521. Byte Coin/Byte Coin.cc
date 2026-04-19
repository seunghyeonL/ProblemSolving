#include <bits/stdc++.h>
using namespace std;

const int NMX = 15;
int N, W;
int arr[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    long long cw = W;
    bool is_rising = false;
    long long n = 0; // 코인 보유량

    for (int i = 0; i < N - 1; i++)
    {
        if (!is_rising && arr[i + 1] > arr[i])
        {
            n = cw / arr[i];
            cw = cw % arr[i];
            is_rising = true;
        }
        else if (is_rising && arr[i + 1] < arr[i])
        {
            cw += n * arr[i];
            n = 0;
            is_rising = false;
        }
    }

    if (n > 0)
    {
        cw += n * arr[N - 1];
        n = 0;
    }

    cout << cw;

    // inputFileStream.close();
    return 0;
}