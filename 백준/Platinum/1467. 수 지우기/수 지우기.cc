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
        각 자리마다 가능한 가장 큰 수 넣기
    */

    // NMX == 1000 => O(N^2) 가능
    int N, E;
    vector<int> v; // 오름차순으로 끊은 숫자들
    {
        string line;
        cin >> line;

        N = line.size();

        for (int c : line)
            v.push_back(c - '0');
    }

    vector<int> can_erase_cnt(10); // 지울 숫자 개수
    {
        string line;
        cin >> line;

        E = line.size();

        for (char c : line)
            can_erase_cnt[c - '0']++;
    }

    vector<bool> erased_pos(N);

    string ans;
    ans.resize(N - E);
    int erase_cnt = 0;
    int vi = 0;

    for (int ai = 0; ai < N - E; ai++)
    {
        for (int tn = 9; tn >= 0; tn--) // ans[ai] 에 넣을 수
        {
            int cp_erase_cnt = erase_cnt;
            vector<int> cp_can_erase_cnt = can_erase_cnt;
            int tvi = -1; // vi 부터 최초로 등장하는 tn idx
            for (int i = vi; i < N; i++)
            {
                if (v[i] == tn)
                {
                    tvi = i;
                    break;
                }

                if (++cp_erase_cnt > E)
                    break;

                if (--cp_can_erase_cnt[v[i]] < 0)
                    break;
            }

            if (tvi == -1)
                continue;

            vector<int> digit_remain(10);
            for (int i = tvi + 1; i < N; i++)
            {
                digit_remain[v[i]]++;
            }

            bool possible = true;
            for (int i = 0; i < 10; i++)
            {
                if (cp_can_erase_cnt[i] > digit_remain[i])
                    possible = false;
            }

            if (!possible)
                continue;

            ans[ai] = '0' + v[tvi];
            vi = tvi + 1;
            erase_cnt = cp_erase_cnt;
            can_erase_cnt = cp_can_erase_cnt;

            break;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}