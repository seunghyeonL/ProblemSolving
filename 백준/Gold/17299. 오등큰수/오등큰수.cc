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

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> cnt_A(1010101);
    for (int n : A)
        cnt_A[n]++;

    // idx of A
    stack<int> stk;

    vector<int> ans(N, -1);

    for (int i = 0; i < N; i++)
    {
        while (!stk.empty() && cnt_A[A[stk.top()]] < cnt_A[A[i]])
        {
            ans[stk.top()] = A[i];
            stk.pop();
        }

        stk.push(i);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';

    // inputFileStream.close();
    return 0;
}