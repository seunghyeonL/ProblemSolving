#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int> pq;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*

    */

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (n > 0)
            pq.push(n);
        else
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    // inputFileStream.close();
    return 0;
}