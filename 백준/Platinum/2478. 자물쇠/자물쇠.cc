#include <bits/stdc++.h>
using namespace std;

int N;

int next_pos(int i)
{
    return (i + 1) % N;
}

int prev_pos(int i)
{
    return (i - 1 + N) % N;
}

int next_val(int val)
{
    return (val + 1) % N;
}

int prev_val(int val)
{
    return (N + val - 1) % N;
}

bool is_all_reversed(const deque<int> &dq)
{
    for (int i = 0; i < N; i++)
    {
        if (dq[i] != next_val(dq[next_pos(i)]))
            return false;
    }

    return true;
}

bool is_correct(const deque<int> &dq)
{
    for (int i = 0; i < N; i++)
    {
        if (next_val(dq[i]) != dq[next_pos(i)])
            return false;
    }

    return true;
}

int find_k1(const deque<int> &dq)
{
    int ret = 0;
    for (int i = 1; i < N; i++)
    {
        if (dq[i] == 0)
        {
            ret = N - i;
            break;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    deque<int> dq(N);
    for (int i = 0; i < N; i++)
    {
        cin >> dq[i];
        --dq[i];
    }

    if (is_correct(dq))
    {
        for (int k2 = 1; k2 < N; k2++)
        {
            dq.push_front(dq.back());
            dq.pop_back();

            int k1 = find_k1(dq);

            if (k1 == 0)
                continue;

            cout << k1 << '\n';
            cout << 1 << ' ' << 1 << '\n';
            cout << k2 << '\n';

            return 0;
        }
    }

    if (is_all_reversed(dq))
    {
        for (int k2 = 1; k2 < N; k2++)
        {
            dq.push_front(dq.back());
            dq.pop_back();

            reverse(dq.begin(), dq.end());

            int k1 = find_k1(dq);
            if (k1 == 0)
            {
                reverse(dq.begin(), dq.end());
                continue;
            }

            cout << k1 << '\n';
            cout << 1 << ' ' << N << '\n';
            cout << k2 << '\n';

            return 0;
        }
    }

    for (int k2 = 1; k2 < N; k2++)
    {
        dq.push_front(dq.back());
        dq.pop_back();

        int l{}; // 내림차순 첫 지점
        // 1 차이 내림차순 구간이 될때까지 키우기
        while (dq[l] != next_val(dq[next_pos(l)]))
            l = next_pos(l);

        // 이미 구간 안이면 앞으로 땡기기
        while (dq[prev_pos(l)] == next_val(dq[l]))
            l = prev_pos(l);

        int r = l; // 내림차순 끝 지점
        while (dq[r] == next_val(dq[next_pos(r)]))
            r = next_pos(r);

        if (l > r)
            continue;

        reverse(dq.begin() + l, dq.begin() + r + 1);

        int k1 = find_k1(dq);
        if (k1 == 0)
        {
            reverse(dq.begin() + l, dq.begin() + r + 1);
            continue;
        }

        cout << k1 << '\n';
        cout << l + 1 << ' ' << r + 1 << '\n';
        cout << k2 << '\n';

        return 0;
    }

    // inputFileStream.close();
    return 0;
}