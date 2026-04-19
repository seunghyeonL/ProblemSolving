#include <bits/stdc++.h>
using namespace std;

int N, L;
int A[5000001];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // 값, idx
    deque<pair<int, int>> dq;

    for (int i = 0; i < N; i++)
    {
        while (!dq.empty() && dq.back().first > A[i])
        {
            dq.pop_back();
        }

        dq.emplace_back(A[i], i);

        if (i >= L && dq.front().second == i - L)
        {
            dq.pop_front();
        }

        cout << dq.front().first << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}