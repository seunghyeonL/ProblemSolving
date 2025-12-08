#include <bits/stdc++.h>
using namespace std;

// 비워지지 않은 수식으로 부터 가능한 진법을 추리고
// 가능한 진법으로 지워진 수식을 풀었을 때 답이 동일하지 않으면 ? 동일하면 그 값

const int NMX = 100;
int N;
int max_num;

bool is_possible[10];

int pow(int a, int p)
{
    int ret = 1;
    while (p-- > 0)
    {
        ret *= a;
    }
    return ret;
}

int n_to_10(const string& a, int n)
{
    int ret = 0;
    
    for (char c : a)
    {
        int num = c - '0';
        
        ret = ret * n + num;
    }
    
    return ret;
}

string ten_to_n(int a, int n)
{
    string ret{};
    
    while (a > 0)
    {
        int r = a % n;
        ret.push_back('0' + r);
        a /= n;
    }
    
    if (ret.empty()) ret.push_back('0');
    
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<string> solution(vector<string> expressions) {    
    N = expressions.size();
    
    fill(is_possible, is_possible + 10, true);
    
    max_num = 0;
    for (const string& str : expressions)
    {
        stringstream ss(str);
            
        string sa, sb, sc;
        char op1, op2;
        ss >> sa >> op1 >> sb >> op2 >> sc;
        
        for (const string& cs : {sa, sb, sc})
        {
            if (cs == "X") continue;
            for (char ch : cs)
            {
                int num = ch - '0';
                max_num = max(max_num, num);
            }
        }
        
        if (sc == "X") continue;
        
        for (int n = 2 ; n <= 9 ; n++)
        {
            if (!is_possible[n] || n <= max_num) continue;
            
            if (op1 == '+')
            {
                if (n_to_10(sa, n) + n_to_10(sb, n) != n_to_10(sc, n))
                    is_possible[n] = false;
            }
            else
            {
                if (n_to_10(sa, n) - n_to_10(sb, n) != n_to_10(sc, n))
                    is_possible[n] = false;
            }
        }
    }
    
    vector<string> ans;
    
    for (const string& str : expressions)
    {
        if (str.back() != 'X') 
            continue;
        
        stringstream ss(str);
            
        string sa, sb;
        char op1;
        ss >> sa >> op1 >> sb;
        
        string x{};
        bool ok = true;
        
        for (int n = 2 ; n <= 9 ; n++)
        {
            if (!is_possible[n] || n <= max_num) continue;
            
            if (op1 == '+')
            {
                string nx = ten_to_n(n_to_10(sa, n) + n_to_10(sb, n), n);
                
                if (x.empty()) x = nx;
                else if (x != nx) 
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                string nx = ten_to_n(n_to_10(sa, n) - n_to_10(sb, n), n);
                
                if (x.empty()) x = nx;
                else if (x != nx) 
                {
                    ok = false;
                    break;
                }
            }
        }
        
        ss = stringstream();
        ss << sa << ' ' << op1 << ' ' << sb << " = " << (ok ? x : "?");
        
        ans.push_back(ss.str());
    }
    
    return ans;
}