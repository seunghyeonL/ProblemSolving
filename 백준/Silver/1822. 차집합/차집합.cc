#include <bits/stdc++.h>
using namespace std;

const int NMX = 500000;
int Na, Nb;
int A[NMX];
int B[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> Na >> Nb;

    for (int i = 0; i < Na; i++)
        cin >> A[i];

    sort(A, A + Na);

    for (int i = 0; i < Nb; i++)
        cin >> B[i];

    sort(B, B + Nb);

    vector<int> ans;
    for (int i = 0; i < Na; i++)
    {
        if (!binary_search(B, B + Nb, A[i]))
            ans.push_back(A[i]);
    }

    cout << ans.size() << '\n';
    for (int el : ans)
        cout << el << ' ';

    // inputFileStream.close();
    return 0;
}
