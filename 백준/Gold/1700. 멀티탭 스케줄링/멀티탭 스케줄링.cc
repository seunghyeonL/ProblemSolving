#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        현재 멀티탭에 사용되고 있는 상품 중 가장 뒷 시간에 사용될 상품을 현재 사용할 걸로 바꿔주기
    */

    int N, K;
    cin >> N >> K;

    vector<int> usage(K);                 // 물건 사용 순서
    vector<vector<int>> usageIdxs(K + 1); // 물건별 사용 순서 모음
    for (int i = 0; i < K; i++)
    {
        int el;
        cin >> el;

        usage[i] = el;
        usageIdxs[el].push_back(i);
    }

    // 현재 멀티탭에 있는가?, usageIdx
    vector<pair<bool, int>> curUsing(K + 1, {false, -1});
    int useCnt = 0;

    int answer = 0;
    for (int cur : usage)
    {
        if (curUsing[cur].first)
        {
            int &usageIdx = curUsing[cur].second;
            usageIdx = *upper_bound(usageIdxs[cur].begin(), usageIdxs[cur].end(), usageIdx);
            continue;
        }

        if (useCnt < N)
        {
            auto &[isInMultitab, usageIdx] = curUsing[cur];
            isInMultitab = true;
            usageIdx = *upper_bound(usageIdxs[cur].begin(), usageIdxs[cur].end(), usageIdx);
            useCnt++;
            continue;
        }

        // 멀티탭이 다 찼고 cur 자리를 만들어야 할 때
        int mxNextUsageIdx = 0;
        int targetGoods = -1;
        for (int goods = 1; goods <= K; ++goods)
        {
            auto [isInMultitab, usageIdx] = curUsing[goods];
            if (!isInMultitab)
                continue;

            auto it = upper_bound(usageIdxs[goods].begin(), usageIdxs[goods].end(), usageIdx);
            int nextUsageIdx = it == usageIdxs[goods].end() ? K : *it;

            if (nextUsageIdx >= mxNextUsageIdx)
            {
                mxNextUsageIdx = nextUsageIdx;
                targetGoods = goods;
            }
        }

        curUsing[targetGoods].first = false;
        answer++;

        auto &[isInMultitab, usageIdx] = curUsing[cur];
        isInMultitab = true;
        usageIdx = *upper_bound(usageIdxs[cur].begin(), usageIdxs[cur].end(), usageIdx);
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}