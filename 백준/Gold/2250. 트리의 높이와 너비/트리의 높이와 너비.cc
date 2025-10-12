#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N;
int colPos[NMX + 1]; // 각 노드의 열 위치 (루트는 0)
int level[NMX + 1];  // 각 노드의 레벨
int stSize[NMX + 1]; // 각 노드를 루트로 하는 서브트리 사이즈

int LC[NMX + 1];
int RC[NMX + 1];
int mxlv;

int setStSize(int cv)
{
    int lc = LC[cv];
    int rc = RC[cv];

    int res = 1;

    if (lc > 0)
    {
        res += setStSize(lc);
    }

    if (rc > 0)
    {
        res += setStSize(rc);
    }

    return stSize[cv] = res;
}

void solveRec(int cv)
{
    int lc = LC[cv];
    int rc = RC[cv];

    if (lc > 0)
    {
        level[lc] = level[cv] + 1;
        mxlv = max(mxlv, level[lc]);

        colPos[lc] = colPos[cv] - stSize[RC[lc]] - 1;
        solveRec(lc);
    }

    if (rc > 0)
    {
        level[rc] = level[cv] + 1;
        mxlv = max(mxlv, level[rc]);

        colPos[rc] = colPos[cv] + stSize[LC[rc]] + 1;
        solveRec(rc);
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        p, lc, rc에서
        lc 열 위치 == p 열 위치 - lc의 rc 사아즈 - 1
        rc 열 위치 == p 열 위치 + rc의 lc 사이즈 + 1
    */

    // ifstream inputFileStream("input.txt");

    int root{};

    {
        cin >> N;
        vector<bool> isChild(N + 1);
        for (int i = 1; i <= N; i++)
        {
            int p, lc, rc;
            cin >> p >> lc >> rc;

            if (lc > 0)
                isChild[lc] = true;
            if (rc > 0)
                isChild[rc] = true;

            // stSize[0] == 0을 이용하기 위해 없는 자식은 0으로
            LC[p] = lc == -1 ? 0 : lc;
            RC[p] = rc == -1 ? 0 : rc;
        }

        for (int u = 1; u <= N; u++)
        {
            if (!isChild[u])
            {
                root = u;
                break;
            }
        }
    }

    setStSize(root);
    mxlv = 1;

    colPos[root] = 0;
    level[root] = 1;

    solveRec(root);

    vector<int> mnLvPos(N + 1, N + 1);
    vector<int> mxLvPos(N + 1, -(N + 1));

    for (int u = 1; u <= N; u++)
    {
        // cout << stSize[u] << ' ';
        int lv = level[u];
        int cp = colPos[u];

        mnLvPos[lv] = min(mnLvPos[lv], cp);
        mxLvPos[lv] = max(mxLvPos[lv], cp);
    }
    // cout << '\n';

    int mxWidth = 0;
    int tlv = 0;

    for (int lv = 1; lv <= mxlv; lv++)
    {
        // Printc<set<int>>()(levelPos[lv]);
        int width = mxLvPos[lv] - mnLvPos[lv] + 1;
        if (mxWidth < width)
        {
            tlv = lv;
            mxWidth = width;
        }
    }

    cout << tlv << ' ' << mxWidth << '\n';

    // inputFileStream.close();
    return 0;
}