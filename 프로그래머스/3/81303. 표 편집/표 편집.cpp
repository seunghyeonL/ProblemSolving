#include <bits/stdc++.h>
using namespace std;

// 선택은 한 행씩
// 삭제된 행 정보는 스택에 보관
// 복원시 정확한 위치에 복구하기 위해 행 idx사용
// 범위를 벗어나게 만드는 입력은 주어지지 않음

// 현재 배열 요소에서 삭제되지 않은 바로 오른쪽, 바로 왼쪽 idx를 관리

int N;
vector<bool> is_deleted;
vector<int> prv;
vector<int> nxt;
stack<int> stk;
int cp;

void op_u(int n)
{
    for (int i = 0 ; i < n ; i++)
        if (prv[cp] != -1)
            cp = prv[cp];
}

void op_d(int n)
{
     for (int i = 0 ; i < n ; i++)
        if (nxt[cp] != -1)
            cp = nxt[cp];
}

void op_c()
{
    stk.push(cp);
    
    int np = nxt[cp];
    int pp = prv[cp];
    
    if (np >= 0) prv[np] = pp;
    if (pp >= 0) nxt[pp] = np;
    
    nxt[cp] = -1;
    prv[cp] = -1;
    
    is_deleted[cp] = true;
    
    if (np >= 0) 
        cp = np;
    else
        cp = pp;
}

void op_z()
{
    if (stk.empty())
        return;
    
    int tp = stk.top();
    stk.pop();
    
    for (int d = 1 ; tp - d >= 0 || tp + d < N ; d++)
    {
        if (tp - d >= 0 && !is_deleted[tp - d])
        {
            prv[tp] = tp - d;
            nxt[tp] = nxt[tp - d];
            
            if (prv[tp] >= 0)
                nxt[prv[tp]] = tp;
            
            if (nxt[tp] >= 0)
                prv[nxt[tp]] = tp;
            
            break;
        }
        
        if (tp + d < N && !is_deleted[tp + d])
        {
            nxt[tp] = tp + d;
            prv[tp] = prv[tp + d];
            
            if (prv[tp] >= 0)
                nxt[prv[tp]] = tp;
            
            if (nxt[tp] >= 0)
                prv[nxt[tp]] = tp;
            
            break;
        }
    }
    
    is_deleted[tp] = false;
}

string solution(int n, int k, vector<string> cmd) {
    N = n;
    
    while (!stk.empty())
        stk.pop();
    
    is_deleted.assign(N, false);
    prv.resize(N);
    nxt.resize(N);
    
    iota(prv.begin(), prv.end(), -1);
    iota(nxt.begin(), nxt.end(), 1);
    
    nxt[N - 1] = -1;
    
    cp = k;
    
    // ---

    for (const auto& cm : cmd)
    {
        char tp = cm[0];
        
        int val{};
        if (tp == 'D' || tp == 'U')
            val = stoi(cm.substr(2));
        
        if (tp == 'U')
            op_u(val);
        else if (tp == 'D')
            op_d(val);
        else if (tp == 'C')
            op_c();
        else if (tp == 'Z')
            op_z();
    }
    
    string ans(N, 'O');

    for (int i = 0 ; i < N ; i++)
        if (is_deleted[i])
            ans[i] = 'X';
    
    return ans;
}