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
        거리를 잡고
        가능한지 여부로 이분탐색

        거리를 작게 잡으면 가능하고 거리를 크게 잡으면 불가능
    */

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        cin >> D[i];
    }

    vector<int> AB(N * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            AB[N * i + j] = A[i] + B[j];
        }
    }
    sort(AB.begin(), AB.end());

    vector<int> CD(N * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            CD[N * i + j] = C[i] + D[j];
        }
    }
    sort(CD.begin(), CD.end());

    long long res = 0;
    int l = 0, r = N * N - 1;

    while (l < N * N && r >= 0)
    {
        if (AB[l] + CD[r] == 0)
        {
            // 중복된 값 처리
            int cntab = 1;
            int cntcd = 1;
            while (l < N * N - 1 && AB[l + 1] == AB[l])
            {
                l++;
                cntab++;
            }

            while (r > 0 && CD[r - 1] == CD[r])
            {
                r--;
                cntcd++;
            }

            res += (long long)cntab * cntcd;

            l++;
            r--;
        }
        else if (AB[l] + CD[r] < 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

