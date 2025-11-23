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
    int half = N - 1;

    string line_base;
    line_base.resize(2 * N - 1);
    fill(line_base.begin(), line_base.end(), ' ');

    vector<string> shape(2 * N - 1);

    for (int i = 0; i < N; i++)
    {
        string line = line_base;

        line[half] = '*';
        for (int j = 1; j <= i; j++)
        {
            line[half + j] = '*';
            line[half - j] = '*';
        }
        
        line.resize(half + i + 1);

        shape[i] = line;
        shape[2 * N - 2 - i] = line;
    }

    for (int i = 0; i < 2 * N - 1; i++)
    {
        cout << shape[i];

        if (i < 2 * N - 2)
            cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}