#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
int N;
vector<int> prob[NMX + 1]; // 데드라인별 컵라면수

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
        int dl, val;
        cin >> dl >> val;
        prob[dl].push_back(val);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int t = 1; t <= N; t++)
    {
        if (prob[t].empty())
            continue;

        for (int val : prob[t])
        {
            pq.push(val);
        }

        while (pq.size() > t)
        {
            pq.pop();
        }
    }

    int answer = 0;
    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}