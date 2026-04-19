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
        priority_queue
    */

    int N;
    cin >> N;

    vector<int> queries(N);
    for (int i = 0; i < N; i++)
    {
        cin >> queries[i];
    }

    auto comp = [](const int &a, const int &b)
    {
        int aa = abs(a);
        int ab = abs(b);
        return aa == ab ? a > b : aa > ab;
    };

    priority_queue<int, vector<int>, decltype(comp)>
        pq(comp);

    auto operate = [&](int n)
    {
        if (n == 0)
        {
            if (pq.size() == 0)
            {
                cout << 0 << '\n';
                return;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
        else
        {
            pq.push(n);
        }
    };

    for (int query : queries)
    {
        operate(query);
    }

    // inputFileStream.close();
    return 0;
}
