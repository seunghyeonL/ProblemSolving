#include <bits/stdc++.h>
using namespace std;

const int MMX = 300000;
int N, M;
int arr[MMX];

// m개 이하로 사탕을 최대한 나눠줄때 나눠지는 개수가 N 이하인가?
// N 이하면 더 작게 나눠서 N 개로 나눌 수 있다.
bool check(int m)
{
    int pieces = 0;

    for (int i = 0; i < M; i++)
    {
        int cur = arr[i];

        while (cur > m)
        {
            cur -= m;
            pieces++;
        }

        pieces++;
    }

    if (pieces <= N)
        return true;
    else
        return false;
}

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

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> arr[i];

    int l = 1, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;

    // inputFileStream.close();
    return 0;
}