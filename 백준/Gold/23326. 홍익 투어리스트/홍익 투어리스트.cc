#include <bits/stdc++.h>
using namespace std;

int N, Q;
bool A[5000002];
// 명소idx
set<int> s;

void query1(int i)
{
    A[i] = !A[i];
    if (A[i])
    {
        s.insert(i);
    }
    else
    {
        s.erase(i);
    }
}

void query2(int x, int &p)
{
    p = (p + x) % N;
}

int query3(int p)
{
    auto it = s.lower_bound(p);
    if (it == s.end())
    {
        it = s.lower_bound(0);
    }

    if (it == s.end())
    {
        return -1;
    }

    return p <= *it ? *it - p : N + *it - p;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i])
            s.insert(i);
    }

    int p = 0;
    for (int _ = 0; _ < Q; _++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int i;
            cin >> i;
            query1(i - 1);
        }
        else if (q == 2)
        {
            int x;
            cin >> x;
            query2(x, p);
        }
        else if (q == 3)
        {
            cout << query3(p) << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}

