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

    vector<int> v1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }

    int M;
    cin >> M;

    vector<int> v2(M);
    for (int i = 0; i < M; i++)
    {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());

    for (int n : v2)
    {
        auto [it1, it2] = equal_range(v1.begin(), v1.end(), n);
        cout << distance(it1, it2) << ' ';
    }

    // inputFileStream.close();
    return 0;
}
