#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, string> um;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string page, password;
        cin >> page >> password;
        um[page] = password;
    }

    for (int i = 0; i < M; i++)
    {
        string page;
        cin >> page;
        cout << um[page] << '\n';
    }

    // inputFileStream.close();
    return 0;
}