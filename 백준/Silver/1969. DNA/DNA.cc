#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
const int MMX = 50;
int N, M;

unordered_map<char, int> um{
    {'A', 0},
    {'T', 1},
    {'G', 2},
    {'C', 3}};

int cnt[MMX][4]; //  i인덱스 자리에 c문자 개수; 0 : A, 1 : T, 2 : G, 3 : C
int mxn[MMX];
char mxc[MMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            char c = str[j];
            cnt[j][um[c]]++;
            if (mxn[j] < cnt[j][um[c]])
            {
                mxn[j] = cnt[j][um[c]];
                mxc[j] = c;
            }
            else if (mxn[j] == cnt[j][um[c]] && c < mxc[j])
            {
                mxc[j] = c;
            }
        }
    }

    int hd = 0;
    for (int i = 0; i < M; i++)
    {
        cout << mxc[i];
        hd += N - mxn[i];
    }

    cout << '\n'
         << hd;
    // inputFileStream.close();
    return 0;
}