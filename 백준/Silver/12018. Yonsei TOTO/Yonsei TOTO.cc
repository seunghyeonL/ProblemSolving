#include <bits/stdc++.h>
using namespace std;

const int NMX = 100;
int N, M;
int mil_need[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        과목별로 수강에 성공할 최소 마일리지를 구하고
        정렬한 뒤 작은것부터 수강하기
     */

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int p, l;
        cin >> p >> l;

        vector<int> mil_sub(p);

        for (int j = 0; j < p; j++)
        {
            cin >> mil_sub[j];
        }

        sort(mil_sub.begin(), mil_sub.end(), greater<int>());

        mil_need[i] = p < l ? 1 : mil_sub[l - 1];
    }

    sort(mil_need, mil_need + N);

    int cnt = 0;
    while (M > 0 && cnt < N && M - mil_need[cnt] >= 0)
    {
        M -= mil_need[cnt++];
    }

    cout << cnt;

    // inputFileStream.close();
    return 0;
}