#include <bits/stdc++.h>
using namespace std;

int root(int n)
{
    int res = 1;

    while ((res + 1) * (res + 1) <= n)
        res++;

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

    // ifstream inputFileStream("input.txt");

    string str;
    cin >> str;

    int N = str.size();

    int R, C;
    for (int i = root(N); i >= 1; i--)
    {
        if (N % i == 0)
        {
            // 문제랑 R, C를 반대로 채울거라 R >= C인 조건으로
            C = i;
            R = N / i;
            break;
        }
    }

    vector<vector<char>> table(R, vector<char>(C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            table[i][j] = str[C * i + j];
        }
    }

    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            cout << table[i][j];
        }
    }

    // inputFileStream.close();
    return 0;
}