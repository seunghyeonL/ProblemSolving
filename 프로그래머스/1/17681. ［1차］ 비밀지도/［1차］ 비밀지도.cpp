#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> nto2(int x)
{
    vector<int> ret(N);
    
    for (int i = N - 1 ; x > 0 ; i--, x /= 2)
    {
        ret[i] = x % 2;
    }
    
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    N = n;
    
    vector<string> ans;
    
    for (int i = 0 ; i < N ; i++)
    {
        string line;
        vector<int> line1 = nto2(arr1[i]);
        vector<int> line2 = nto2(arr2[i]);
        
        for (int j = 0 ; j < N ; j++)
        {
            line.push_back((line1[j] | line2[j]) ? '#' : ' ');
        }
        
        ans.push_back(line);
    }
    
    
    return ans;
}