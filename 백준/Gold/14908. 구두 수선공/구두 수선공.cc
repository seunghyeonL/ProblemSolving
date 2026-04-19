#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>; // T, S, i
const int NMX = 1000;
int N;
T arr[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*

    W2 -> W1 - W1 -> W2 < 0 일 경우 순서를 바꿔야함

    T2 * S2 + (T1 + T2) * S1 - T1 * S1 - (T1 + T2) * S2 < 0
    T2 * S1 - T1 * S2 < 0
    T1 * T2 * (S1 / T1 - S2 / T2) < 0
    S1 / T1 < S2 / T2 이면 순서를 바꿔야 함

    => Si / Ti 기준 내림차순

    */

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int T, S;
        cin >> T >> S;

        arr[i] = {T, S, i};
    }

    sort(arr, arr + N,
         [](const T &a, const T &b)
         {
             auto [Ta, Sa, ia] = a;
             auto [Tb, Sb, ib] = b;
             float A = (float)Sa / Ta;
             float B = (float)Sb / Tb;

             return A == B ? ia < ib : A > B;
         });

    for (int i = 0; i < N; i++)
    {
        cout << get<2>(arr[i]) + 1 << ' ';
    }

    // inputFileStream.close();
    return 0;
}