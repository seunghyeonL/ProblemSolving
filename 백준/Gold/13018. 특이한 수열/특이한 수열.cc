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

    int N, K;
    cin >> N >> K;

    // A[i]는 1 ~ N 까지 정수가 모두 등장
    // A[i] == i로 초기 설정해놓으면 N - 1개가 서로소가 아님
    // 서로 다른 두 요소를 swap하면
    // 1이 포함되면 만족하는게 하나가 줄고
    // 아니면 두개가 줄어듬

    if (K == N)
    {
        cout << "Impossible";
        return 0;
    }

    vector<int> v(N + 1);
    iota(v.begin(), v.end(), 0);

    int t_cnt = N - 1;

    int start{};
    if ((t_cnt - K) % 2 == 1)
    {
        swap(v[1], v[2]);
        t_cnt--;
        start = 3;
    }
    else
    {
        start = 2;
    }

    for (int i = start; i < N; i += 2)
    {
        if (t_cnt > K)
        {
            swap(v[i], v[i + 1]);
            t_cnt -= 2;
        }
        else
            break;
    }

    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}