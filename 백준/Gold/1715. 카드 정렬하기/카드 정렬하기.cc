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
        그리디
        priority_queue
        크기가 1이 될 때까지
        제일 작은거 두개를 뺀다음에 더해서
        다시 넣어주기
    */

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        pq.push(n);
    }

    int res = 0;
    while (pq.size() > 1)
    {
        int n1 = pq.top();
        pq.pop();

        int n2 = pq.top();
        pq.pop();

        res += n1 + n2;
        pq.push(n1 + n2);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
