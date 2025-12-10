#include <bits/stdc++.h>
using namespace std;

// 각 점수를 가져가고/안가져가고
// 경우로 나눠서 백트래킹
// 최대 점수차 구하기

const int NMX = 10;
const int I = 11;
vector<int> arr;

bool comp(const vector<int>& a, const vector<int>& b)
{
    int sz = a.size();
    for (int i = sz - 1 ; i >= 0 ; i--)
    {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    
    return false;
}

// info idx, 남은 화살 개수, 점수차, 최대 점수차, 최대 점수차 일때 화살 기록,현재 화살 기록
void bt(int idx, int n, int diff, int& mx_diff, vector<int>& ans, vector<int>& cur)
{
    // pruning
    if (diff + accumulate(arr.begin() + idx, arr.begin() + I, 0, 
                          [](int acc, int cur){ return acc + 10 - cur; }) < mx_diff) return;
    
    if (idx == I)
    {
        // 점수차가 mx_diff 이상이고 현재 조합이 낮은 점수에 더 많이 쐈을떄
        if (diff > mx_diff || diff == mx_diff && comp(ans, cur))
        {
            cout << diff << '\n';
            for (int el : cur)
            {
                cout << el << ' ';
            }
            cout << '\n';
            
            mx_diff = diff;
            ans = cur;
        }
        
        return;
    }
    
    
    if (idx < I - 1)
    {
        if (arr[idx] > 0)
        {
            if (arr[idx] + 1 <= n)
            {
                cur[idx] = arr[idx] + 1;
                bt(idx + 1, n - arr[idx] - 1, diff + (10 - idx), mx_diff, ans, cur);
                cur[idx] = 0;
            }

            bt(idx + 1, n, diff - (10 - idx), mx_diff, ans, cur);
        }
        else
        {
            if (1 <= n)
            {
                cur[idx] = 1;
                bt(idx + 1, n - 1, diff + (10 - idx), mx_diff, ans, cur);
                cur[idx] = 0;
            }

            bt(idx + 1, n, diff, mx_diff, ans, cur);
        }
    }
    else
    {
        // idx == I - 1 == 10 ; 점수 0
        cur[idx] = n;
        bt(idx + 1, 0, diff, mx_diff, ans, cur);
        cur[idx] = 0;
    }
}

vector<int> solution(int n, vector<int> info) 
{
    // n = 3;
    // info = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1};
    arr = info;
    
    vector<int> ans(I, 1);
    vector<int> cur(I);
    int mx_diff = -1000;
    
    bt(0, n, 0, mx_diff, ans, cur);
    
    if (mx_diff <= 0) return {-1};
    else return ans;
}