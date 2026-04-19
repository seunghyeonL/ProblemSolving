#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
deque<int> gear[4];

bool isValid(int gi)
{
    return gi >= 0 && gi < 4;
}

void rotate(int gi, int pgi, int rt)
{
    // 왼쪽 기어 회전 전파
    if (isValid(gi - 1) && gi - 1 != pgi && gear[gi - 1][2] != gear[gi][6])
    {
        rotate(gi - 1, gi, -rt);
    }

    // 오른쪽 기어 회전 전파
    if (isValid(gi + 1) && gi + 1 != pgi && gear[gi][2] != gear[gi + 1][6])
    {
        rotate(gi + 1, gi, -rt);
    }

    // 자신 회전
    if (rt == 1) // 시계
    {
        int b = gear[gi].back();
        gear[gi].pop_back();
        gear[gi].push_front(b);
    }
    else // 반시계
    {
        int f = gear[gi].front();
        gear[gi].pop_front();
        gear[gi].push_back(f);
    }
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        deque 4개 쓰기

        왼쪽 톱니바퀴의 2번 idx 값과 오른쪽 톱니바퀴의 6번 idx 값이 다르면 회전 전파
     */

    for (int i = 0; i < 4; i++)
    {
        string el;
        cin >> el;
        for (char c : el)
        {
            gear[i].push_back(c - '0');
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int g, r;
        cin >> g >> r;
        g--;
        rotate(g, -1, r);
    }

    int res = 0;
    if (gear[0][0] == 1)
        res += 1;
    if (gear[1][0] == 1)
        res += 2;
    if (gear[2][0] == 1)
        res += 4;
    if (gear[3][0] == 1)
        res += 8;

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
