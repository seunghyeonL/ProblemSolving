#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];
int lis[1000001];
int pre[1000001]; // pre[i] : i를 끝으로 하는 최대 길이의 수열에서 i 앞에 오는
                  // 요소

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
    int LMT = N + 1;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        pre[i] = i;
    }

    fill(lis, lis + N, LMT);

    int len = 0;
    for (int i = 0; i < N; i++)
    {
        int cur = arr[i];

        auto it = partition_point(lis, lis + len,
                                  [&](int el) { return arr[el] < cur; });

        int tidx = it - lis;
        if (tidx == len)
            len++;

        pre[i] = tidx == 0 ? i : lis[tidx - 1];
        lis[tidx] = i;
    }

    cout << len << '\n';

    vector<int> history;
    int p = lis[len - 1];

    while (1)
    {
        history.push_back(p);
        if (pre[p] == p)
            break;
        p = pre[p];
    }

    reverse(history.begin(), history.end());
    for (int idx : history)
        cout << arr[idx] << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}

