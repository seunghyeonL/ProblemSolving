#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const ll MAX = 1e18;
ll N;
ll A, B, C, D;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N;
    cin >> A >> B >> C >> D;

    ll l = lcm<ll>(A, C);

    // A, B를 더 비싼 조합으로
    // B / A < D / C <=> B * C < D * A
    if (B * C < D * A) 
    {
        swap(A, C);
        swap(B, D);
    }

    ll mn = MAX;
    for (ll i = 0; i < l / A; i++)
    {
        
        ll p = B * i;
        ll r = N - A * i;
        
        if (r > 0) p += ((r - 1) / C + 1) * D;
        mn = min(mn, p);
    }

    cout << mn;

    // inputFileStream.close();
    return 0;
}