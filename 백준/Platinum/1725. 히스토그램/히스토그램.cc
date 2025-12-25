#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
vector<int> h;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    // height, height높이 직사각형을 만들 수 있는 시작점
    stack<pair<int, int>> stk;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int ci = i;
        while (!stk.empty() && stk.top().first >= h[i])
        {
            auto [height, si] = stk.top();

            ans = max(ans, height * (i - si));
            ci = si;
            stk.pop();
        }

        stk.emplace(h[i], ci);
    }

    while (!stk.empty())
    {
        auto [height, si] = stk.top();
        ans = max(ans, height * (N - si));
        stk.pop();
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}