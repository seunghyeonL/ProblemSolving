#include <bits/stdc++.h>
using namespace std;

string S;
vector<string> partString;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++)
    {
        for (int len = 1; len <= N - i; len++)
        {
            partString.push_back(S.substr(i, len));
        }
    }

    sort(partString.begin(), partString.end());
    partString.erase(unique(partString.begin(), partString.end()), partString.end());

    cout << partString.size() << '\n';

    // inputFileStream.close();
    return 0;
}