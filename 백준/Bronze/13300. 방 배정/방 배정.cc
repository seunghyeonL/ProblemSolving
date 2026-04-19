#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        남녀 구별
        같은 학년끼리
        최대 인원수 K
    */

    using P = pair<int, int>;
    int N, K;
    cin >> N >> K;

    // 학년, 성별
    vector<P> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].second; // 성별
        cin >> v[i].first;  // 학년
    }

    sort(v.begin(), v.end());

    auto [pgr, pge] = v[0];

    int roomCnt = 1;
    int peopleCnt = 0;

    for (auto [cgr, cge] : v)
    {
        if (cgr != pgr || cge != pge || peopleCnt == K)
        {
            roomCnt++;
            peopleCnt = 0;
        }

        pgr = cgr;
        pge = cge;

        peopleCnt++;
    }

    cout << roomCnt << '\n';

    // inputFileStream.close();
    return 0;
}