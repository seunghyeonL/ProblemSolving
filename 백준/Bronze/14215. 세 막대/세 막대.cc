#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    vector<int> L(3);

    cin >> L[0];
    cin >> L[1];
    cin >> L[2];

    sort(L.begin(), L.end());

    if (L[2] >= L[0] + L[1])
        L[2] = L[0] + L[1] - 1;

    cout << L[0] + L[1] + L[2];

    // inputFileStream.close();
    return 0;
}