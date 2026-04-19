#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, vector<string>> gm; // group : member
unordered_map<string, string> mg;         // member : group

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string gn; // 그룹이름
        cin >> gn;

        int num; // 그룹 인원
        cin >> num;

        while (num-- > 0)
        {
            string mn; // 멤버 이름
            cin >> mn;

            gm[gn].push_back(mn);
            mg[mn] = gn;
        }
    }

    for (auto &[gn, mns] : gm)
    {
        sort(mns.begin(), mns.end());
    }

    for (int i = 0; i < M; i++)
    {
        string query;
        int category;

        cin >> query >> category;

        if (category == 0)
        {
            for (string &mn : gm[query])
            {
                cout << mn << '\n';
            }
        }
        else
        {
            cout << mg[query] << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}