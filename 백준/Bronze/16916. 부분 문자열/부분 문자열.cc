#include <bits/stdc++.h>
using namespace std;    

const int SZMX = 1000000;
string S, P;
int sz;
int F[SZMX]; // P 실패함수

void build_F()
{
    for (int i = 1, j = 0; i < P.size(); i++)
    {
        while (j > 0 && P[i] != P[j])
            j = F[j - 1];

        if (P[i] == P[j])
            F[i] = ++j;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> S >> P;
    sz = S.size();

    build_F();

    int ans = 0;
    for (int i = 0, j = 0; i < sz; i++)
    {
        while (j > 0 && S[i] != P[j])
            j = F[j - 1];

        if (S[i] == P[j])
            j++;

        if (j == P.size())
        {
            ans = 1;
            break;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}