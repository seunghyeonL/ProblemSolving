#include <bits/stdc++.h>
using namespace std;

vector<string> board(5);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }

    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (j >= board[i].size())
                continue;

            cout << board[i][j];
        }
    }

    // inputFileStream.close();
    return 0;
}