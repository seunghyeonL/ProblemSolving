#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
int LC[NMX + 1];
int RC[NMX + 1];

int visCnt;
long long answer;

void likeInOrder(int p)
{
    if (p > 1)
    {
        answer++;
    }

    int lc = LC[p];
    int rc = RC[p];

    if (lc > 0)
    {
        likeInOrder(lc);
        answer++;
    }

    if (rc > 0)
    {
        visCnt++;
        likeInOrder(rc);
        if (visCnt < N)
        {
            answer++;
        }
    }
    else
    {
        visCnt++;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        cin >> LC[a];
        cin >> RC[a];
    }

    likeInOrder(1);

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}