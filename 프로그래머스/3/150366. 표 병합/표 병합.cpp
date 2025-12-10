#include <bits/stdc++.h>
using namespace std;

const int N = 50;

string values[N * N];

int uf[N * N];

int find_root(int u)
{
    if (uf[u] < 0) return u;
    return uf[u] = find_root(uf[u]);
}

bool union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);
    
    if (u == v) return false;
    
    // v -> u
    if (values[u].empty())
        values[u] = values[v];    
    
    uf[v] = u;
    
    return true;
}

int get_node_num(int x, int y)
{
    return x * N + y;
}

string& get_value(int x, int y)
{
    return values[find_root(get_node_num(x, y))];
}

void operate_update(int r, int c, const string& val)
{
    --r; --c;
    string& value = get_value(r, c);
    value = val;
}

void operate_update(const string& val1, const string& val2)
{
    for (int u = 0 ; u < N * N ; u++)
    {
        string& value = get_value(u / N, u % N);
        if (value == val1) 
            value = val2;
    }
}

void operate_merge(int r1, int c1, int r2, int c2)
{
    --r1; --c1; --r2; --c2;
    int u = get_node_num(r1, c1);
    int v = get_node_num(r2, c2);
    
    union_set(u, v);
}

void operate_unmerge(int r, int c)
{
    --r; --c;
    int tv = get_node_num(r, c);
    int rtv = find_root(tv);
    
    string tval = get_value(r, c);
    
    vector<int> cluster;
    
    for (int u = 0 ; u < N * N ; u++)
    {
        if (find_root(u) == rtv) 
            cluster.push_back(u);
    }
    
    for (int u : cluster)
    {
        uf[u] = -1;
        values[u] = "";
    }
    
    values[tv] = tval;
}

string operate_print(int r, int c)
{
    --r; --c;
    int u = get_node_num(r, c);
    
    string ret = get_value(r, c);
    
    return (ret.empty() ? "EMPTY" : ret);
}

vector<string> solution(vector<string> commands)
{
    memset(uf, -1, sizeof(uf));
    fill(values, values + N * N, "");
    
    vector<string> ans;
    for (const auto& command : commands)
    {
        stringstream ss(command);
        
        string t;
        ss >> t;
        
        if (t == "UPDATE")
        {
            vector<string> opers;
            string oper;
            
            while (ss >> oper)
                opers.push_back(oper);
            
            if (opers.size() == 2)
                operate_update(opers[0], opers[1]);
            else if (opers.size() == 3)
                operate_update(stoi(opers[0]), stoi(opers[1]), opers[2]);
                
        }
        else if (t == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            operate_merge(r1, c1, r2, c2);
        }
        else if (t == "UNMERGE")
        {
            int r, c;
            ss >> r >> c;
            operate_unmerge(r, c);
        }
        else if (t == "PRINT")
        {
            int r, c;
            ss >> r >> c;
            ans.push_back(operate_print(r, c));
        }
        
        // for (int i = 1 ; i <= 5 ; i++)
        // {
        //     for (int j = 1 ; j <= 5 ; j++)
        //         cout << operate_print(i, j) << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    
    return ans;
}