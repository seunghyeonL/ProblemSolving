#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        자음 2개 이상
        모음 1개 이상
        오름차순
     */

    int L, C;
    cin >> L >> C;

    vector<char> v(C);
    for (int i = 0; i < C; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> mask(C);
    fill(mask.begin(), mask.begin() + L, 1);
    unordered_set<char> us{'a', 'e', 'i', 'o', 'u'};

    do
    {
        int gcnt{}; // 자음갯수
        int mcnt{}; // 모음갯수
        vector<char> cur;

        for (int i = 0; i < C; i++)
        {
            if (mask[i])
            {
                cur.push_back(v[i]);
                if (us.count(v[i]))
                {
                    mcnt++;
                }
                else
                {
                    gcnt++;
                }
            }
        }

        if (gcnt >= 2 && mcnt >= 1)
        {
            for (char el : cur)
                cout << el;
            cout << '\n';
        }

    } while (prev_permutation(mask.begin(), mask.end()));

    // inputFileStream.close();
    return 0;
}