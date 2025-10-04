#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        priority queue 에서 가장 작은 값 두개를 뺴서 더한 값 두개를 다시
       넣어주기 반복
     */

    int N, M;
    cin >> N >> M;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        pq.push(n);
    }

    for (int i = 0; i < M; i++)
    {
        ll n1 = pq.top();
        pq.pop();
        ll n2 = pq.top();
        pq.pop();

        pq.push(n1 + n2);
        pq.push(n1 + n2);
    }

    ll answer = 0;
    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
