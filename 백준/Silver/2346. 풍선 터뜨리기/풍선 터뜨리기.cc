#include <bits/stdc++.h>
using namespace std;    

int N;
deque<pair<int, int>> dq; // 번호, 이동정보

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;
        dq.push_back({i, n});
    }

    while (!dq.empty())
    {
        auto [i, n] = dq[0];
        cout << i << ' ';

        dq.pop_front();

        bool sign = n > 0;
        n = abs(n);

        if (sign)
            n--;

        while (n-- > 0)
        {
            if (sign)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    // inputFileStream.close();
    return 0;
}