#include <bits/stdc++.h>
using namespace std;

// 최적의 경우는 절대 친구들의 동선이 겹치지 않는다.
// 친구들의 모든 순서로
// 각 weak point에서 친구들이 이동할 수 있는 만큼 뛰고 지나온 마지막 weak point 다음 weak point로 이동
// 처음 시작 weak point + 12 point 에서 멈출 수 있는 경우 중 최소 친구 수

const int INF = 9;

int solution(int n, vector<int> weak, vector<int> dist) 
{    
    int W = weak.size();
    int F = dist.size();
    
    for (int i = 0 ; i < W ; i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    
    int ans = INF;
    
    do 
    {
        for (int si = 0 ; si < W ; si++) // 점검 시작 idx
        {
            int ci = si;
            for (int fi = 0 ; fi < F ; fi++)
            {
                int ni = ci + 1;
                while (weak[ni] <= weak[ci] + dist[fi])
                    ni++;
                
                // cout << si << ' ' << ci << ' ' << ni << ' ' << fi << ' ' << '\n';
                
                if (ni >= si + W) 
                {
                    ans = min(ans, fi + 1);
                    break;
                }
                
                ci = ni;
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    return (ans == INF ? -1 : ans);
}