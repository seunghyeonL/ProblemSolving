#include <bits/stdc++.h>
using namespace std;

vector<int> val{3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2,
                2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

const int NMX = 2000;
int table[2 * NMX][2 * NMX];
// table[i][j] = table[i - 1][j] + table[i - 1][j + 1]

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

    string A, B;
    cin >> A >> B;

    int N = A.size();

    for (int i = 0; i < N; i++)
    {
        table[0][2 * i] = val[A[i] - 'A'];
        table[0][2 * i + 1] = val[B[i] - 'A'];
    }

    for (int i = 1; i < 2 * N; i++)
    {
        for (int j = 0; j < 2 * N - i; j++)
        {
            table[i][j] = (table[i - 1][j] + table[i - 1][j + 1]) % 10;
        }
    }

    cout << table[2 * N - 2][0] << table[2 * N - 2][1];

    // inputFileStream.close();
    return 0;
}