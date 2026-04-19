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
        b가 몇번째로 큰 수 인지 체크하고
        i 번째로 큰 b요소와 i 번째로 작은 a요소 곱해서 더하기
        -> 그냥 둘다 정렬
    */

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int res = 0;

    for (int i = 0; i < N; i++)
    {
        res += A[i] * B[i];
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
