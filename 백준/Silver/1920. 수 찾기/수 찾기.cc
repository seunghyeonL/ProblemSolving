#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        배열 요소 이분탐색
        정렬하고 해야함
    */

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int M;
    cin >> M;

    vector<int> X(M);
    for (int i = 0; i < M; i++)
    {
        cin >> X[i];
    }

    for (int x : X)
    {
        cout << binary_search(A.begin(), A.end(), x) << '\n';
    }

    // inputFileStream.close();
    return 0;
}