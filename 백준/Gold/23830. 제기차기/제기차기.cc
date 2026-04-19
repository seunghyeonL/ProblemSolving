#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NMX = 100000;
int N;
int p, q, r;
ll S;
int A[NMX];

// 청소를 안해도 되는가?
bool check(ll k)
{
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        int sc = A[i];

        if (sc < k)
            sum += sc + q;
        else if (sc > k + r)
            sum += sc - p;
        else
            sum += sc;
    }

    if (sum >= S)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> p >> q >> r >> S;

    ll lb = 1, rb = 1e15;
    while (lb <= rb)
    {
        ll m = (lb + rb) / 2;
        if (check(m))
            rb = m - 1;
        else
            lb = m + 1;
    }

    cout << (lb > 1e15 ? -1 : lb);

    inputFileStream.close();
    return 0;
}