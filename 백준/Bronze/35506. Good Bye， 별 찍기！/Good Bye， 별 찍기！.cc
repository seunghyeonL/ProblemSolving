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

    int N;
    cin >> N;

    string base_line1;
    for (int i = 0; i < 2 * N; i++)
        base_line1.push_back(' ');

    string base_line2;
    for (int i = 0; i < 2 * N + 1; i++)
        base_line2.push_back(' ');

    vector<string> v1(2 * N, base_line1);
    vector<string> v2(2 * N, base_line2);

    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            if (i + j == 2 * N - 1)
                v1[i][j] = '*';
        }
    }

    // for (int i = 0; i < 2 * N; i++)
    // {
    //     for (int j = 0; j < 2 * N; j++)
    //         cout << v1[i][j];
    //     cout << '\n';
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + j == N - 1)
            {
                v2[i][j] = '*';
                v2[2 * N - 1 - i][j] = '*';
                v2[i][2 * N - j] = '*';
                v2[2 * N - 1 - i][2 * N - j] = '*';
            }
        }
    }

    // for (int i = 0; i < 2 * N; i++)
    // {
    //     for (int j = 0; j < 2 * N + 1; j++)
    //         cout << v2[i][j];
    //     cout << '\n';
    // }

    for (int i = 0; i < 2 * N; i++)
        cout << v1[i] << ' ' << v2[i] << '\n';

    // inputFileStream.close();
    return 0;
}