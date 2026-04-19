#include <bits/stdc++.h>
using namespace std;

int N, W, L;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        N : 트럭 갯수
        W : 다리 길이
        L : 다리 최대 하중

        1초마다 1씩 이동
    */

    cin >> N >> W >> L;

    queue<int> trucks;

    for (int i = 0; i < N; i++)
    {
        int truck;
        cin >> truck;
        trucks.push(truck);
    }

    int time = 0;
    // 트럭 무게, 진입 시간
    queue<pair<int, int>> q;

    int cl = 0;
    while (!q.empty() || !trucks.empty())
    {
        time++;
        while (!q.empty() && q.front().second + W <= time)
        {
            cl -= q.front().first;
            q.pop();
        }

        if (!trucks.empty() && cl + trucks.front() <= L)
        {
            q.emplace(trucks.front(), time);
            cl += trucks.front();
            trucks.pop();
        }
    }

    cout << time << '\n';

    // inputFileStream.close();
    return 0;
}
