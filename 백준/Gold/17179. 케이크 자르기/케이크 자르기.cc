#include <bits/stdc++.h>
using namespace std;

const int MMX = 1000;
const int LMX = 4000000;
int N, M, L;
int cn;
vector<int> cut_pos;
vector<int> cut_len;

// 모든 조각이 mn_len이상이 되도록 자를때 필요한 횟수가 cn 이상인가?
bool check(int mn_len)
{
    int len = 0;
    int pieces = 0; // 잘린 개수
    for (int el : cut_len)
    {
        if (len + el >= mn_len)
        {
            len = 0;
            pieces++;
        }
        else
        {
            len += el;
        }
    }

    // 더 많이 잘라서 만들 수 있으면 좀 덜잘라서 하면 정확히 처리 가능
    if (pieces - 1 >= cn)
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
        잘랐을때 제일 작은 길이가 최대가 되도록

        모든 조각이 mn_len보다 커지게 할 수 있는가?
    */

    cin >> N >> M >> L;

    cut_pos.push_back(0);
    for (int i = 0; i < M; i++)
    {
        int pos;
        cin >> pos;
        cut_pos.push_back(pos);
    }
    cut_pos.push_back(L);

    for (int i = 1; i <= M + 1; i++)
    {
        cut_len.push_back(cut_pos[i] - cut_pos[i - 1]);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> cn;

        int l = 1, r = LMX;

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (check(m))
                l = m + 1;
            else
                r = m - 1;
        }

        cout << r << '\n';
    }

    // inputFileStream.close();
    return 0;
}