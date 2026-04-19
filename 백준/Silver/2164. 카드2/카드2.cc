#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    int N;
    cin >> N;

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() > 1)
    {
        q.pop();
        int n = q.front();
        q.pop();
        q.push(n);
    }

    cout << q.front() << '\n';

    // inputFileStream.close();
    return 0;
}
