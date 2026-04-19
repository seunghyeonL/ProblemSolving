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
        최소 간격이 l이 되도록 만들 수 있는가?
        로 이분탐색

        l을 최대 구간 길이로 잡고
        구간 사이 간격을 l 로 나눠서 휴계소를 몇개 지어야 되는지 판별하고 M보다 큰지 작은지 체크하기

        개수 = 간격 / l;

    */

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> rests(N + 2);
    vector<int> intervals(N + 1);

    rests[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> rests[i];
    }
    rests[N + 1] = L;

    sort(rests.begin(), rests.end());

    for (int i = 0; i <= N; i++)
    {
        intervals[i] = rests[i + 1] - rests[i];
    }

    // for (int el : intervals)
    // {
    //     cout << el << ' ';
    // }
    // cout << '\n';

    // 최대구간을 l로 잡을때 휴계소를 M개이하로 지어야 하는가
    // M개보다 작게 지을때 l이 가능하다면 M개여도 가능하니까
    auto check = [&](int l)
    {
        int need = 0;

        for (int i = 0; i <= N; i++)
        {
            int interval = intervals[i];
            need += (interval - 1) / l; // 나눠떨어질때 보정
        }

        return need <= M;
    };

    int left = 1;
    int right = L - 1;

    while (left <= right)
    {
        // 최대 구간 길이
        int mid = (left + right) / 2;

        if (check(mid))
        {
            // 가능하면 구간 길이 줄여주기 -> 필요 휴계소 개수 증가
            right = mid - 1;
        }
        else
        {
            // 못지으면 구간 길이를 늘리기 -> 필요 휴계소 개수 감소
            left = mid + 1;
        }
    }

    cout << left << '\n';

    // inputFileStream.close();
    return 0;
}

