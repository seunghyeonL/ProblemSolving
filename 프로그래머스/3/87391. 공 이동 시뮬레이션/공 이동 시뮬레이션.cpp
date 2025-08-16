#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    long long L, R;
    bool empty() const { return L > R; }
};

long long solution(int n, int m, int x, int y, vector<vector<int>> queries)
{
    Interval row{x, x};
    Interval col{y, y};

    auto intersect_and_assign = [&](Interval &seg, long long a, long long b, int lo, int hi)
    {
        long long L2 = max<long long>(lo, a);
        long long R2 = min<long long>(hi, b);
        if (L2 > R2)
        {
            seg.L = 1;
            seg.R = 0;
            return;
        }
        seg.L = (int)L2;
        seg.R = (int)R2;
    };

    auto expand_col = [&](int dir, long long d)
    {
        long long L = col.L, R = col.R;
        long long a, b;
        if (dir == 0)
        { 
            if (L == 0)
            {
                a = 0;
                b = R + d;
            } 
            else
            {
                a = L + d;
                b = R + d;
            }
        }
        else
        { 
            if (R == m - 1)
            {
                a = L - d;
                b = m - 1;
            }
            else
            {
                a = L - d;
                b = R - d;
            }
        }
        intersect_and_assign(col, a, b, 0, m - 1);
    };

    auto expand_row = [&](int dir, long long d)
    {
        long long L = row.L, R = row.R;
        long long a, b;
        if (dir == 2)
        {
            if (L == 0)
            {
                a = 0;
                b = R + d;
            }
            else
            {
                a = L + d;
                b = R + d;
            }
        }
        else
        {
            if (R == n - 1)
            {
                a = L - d;
                b = n - 1;
            }
            else
            {
                a = L - d;
                b = R - d;
            }
        }
        intersect_and_assign(row, a, b, 0, n - 1);
    };

    for (int i = queries.size() - 1; i >= 0; --i)
    {
        int dir = queries[i][0];
        long long dist = queries[i][1];

        if (dir == 0 || dir == 1)
            expand_col(dir, dist);
        else
            expand_row(dir, dist);

        if (row.empty() || col.empty())
            return 0LL;
    }

    long long h = row.R - row.L + 1;
    long long w = col.R - col.L + 1;
    return h * w;
}
