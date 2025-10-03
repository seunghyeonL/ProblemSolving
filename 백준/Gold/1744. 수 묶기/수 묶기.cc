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

    /*
        수들을 정렬하고
        가까운 애들끼리 묶기
        0의 경우 음수랑 묶이면 묶고 양수랑 묶이면 안묶기
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int answer = 0;

    if (N == 1)
    {
        cout << v[0] << '\n';
        return 0;
    }

    int l = 0;
    int r = N - 1;

    while (l < N - 1 && v[l + 1] <= 0)
    {
        answer += v[l] * v[l + 1];
        l += 2;
    }

    if (l < N && v[l] < 0)
    {
        answer += v[l];
        l++;
    }

    while (r > 0 && v[r - 1] > 1)
    {
        answer += v[r] * v[r - 1];

        r -= 2;
    }

    while (l <= r)
    {
        answer += v[r--];
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
