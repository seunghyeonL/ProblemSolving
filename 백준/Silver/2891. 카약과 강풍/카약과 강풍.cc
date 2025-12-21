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

    // 앞에서부터 훑으면서
    // 부서진팀은 앞팀한테 먼저 부탁하기

    int N, S, R;
    cin >> N >> S >> R;

    vector<int> arr(N + 1, 1); // arr[i] : i팀의 카약 개수

    for (int i = 0; i < S; i++)
    {
        int n;
        cin >> n;
        arr[n]--;
    }

    for (int i = 0; i < R; i++)
    {
        int n;
        cin >> n;
        arr[n]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            if (i - 1 >= 1 && arr[i - 1] == 2)
            {
                arr[i - 1] = 1;
                arr[i] = 1;
            }
        }

        if (arr[i] == 0)
        {
            if (i + 1 <= N && arr[i + 1] == 2)
            {
                arr[i + 1] = 1;
                arr[i] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (arr[i] == 0)
            ans++;

    cout << ans;

    // inputFileStream.close();
    return 0;
}
