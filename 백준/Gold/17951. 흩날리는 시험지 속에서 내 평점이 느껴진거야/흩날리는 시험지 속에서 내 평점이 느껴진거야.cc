#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, K;
int score[NMX];

bool check(int mn_score)
{
    int acc = 0;
    int cnt = 0; // 그룹 개수

    for (int i = 0; i < N; i++)
    {
        int sc = score[i];
        if (acc + sc >= mn_score)
        {
            acc = 0;
            cnt++;
        }
        else
        {
            acc += sc;
        }
    }

    if (cnt >= K)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        K개의 그룹일 때 '그룹의 합'의 최소값

        그룹을 나눌때 mn_score 보다 크도록 나누기
        그때 K개 이상의 그룹으로 나눌 수 있는지 체크 => parametric search

        mn_score가 가능하면 더 작은 score로도 가능
        불가능하면 더 큰 score로도 불가능
     */

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> score[i];

    int l = 0, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }

    cout << r;

    // inputFileStream.close();
    return 0;
}