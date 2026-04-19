#include <bits/stdc++.h>
using namespace std;

vector<string> solveRec(int N)
{
    vector<string> res(N, string(N, ' '));

    if (N == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            fill(res[i].begin(), res[i].end(), '*');
        }
        res[1][1] = ' ';

        return res;
    }

    vector<string> part = solveRec(N / 3);

    int m = N / 3;
    for (int i = 0; i < N / 3; i++)
    {
        copy(part[i].begin(), part[i].end(), res[i].begin());
        copy(part[i].begin(), part[i].end(), res[i].begin() + m);
        copy(part[i].begin(), part[i].end(), res[i].begin() + 2 * m);
        copy(part[i].begin(), part[i].end(), res[i + m].begin());

        copy(part[i].begin(), part[i].end(), res[i + m].begin() + 2 * m);
        copy(part[i].begin(), part[i].end(), res[i + 2 * m].begin());
        copy(part[i].begin(), part[i].end(), res[i + 2 * m].begin() + m);
        copy(part[i].begin(), part[i].end(), res[i + 2 * m].begin() + 2 * m);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    int N;
    cin >> N;

    vector<string> res = solveRec(N);

    for (string line : res)
    {
        cout << line << '\n';
    }

    // inputFileStream.close();
    return 0;
}
