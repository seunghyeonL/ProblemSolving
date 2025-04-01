#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = plays.size();
    
    unordered_map<string, vector<int>> um;
    
    for(int i = 0 ; i < size ; i++)
    {
        um[genres[i]].push_back(i);
    }
    
    vector<pair<string, vector<int>>> v(um.begin(), um.end());
    auto comp1 = [&plays](auto a, auto b) -> bool
    {
        vector<int> va = a.second;
        vector<int> vb = b.second;
        
        int sumA = accumulate(va.begin(), va.end(), 0, [&plays](int acc, int cur){ return acc + plays[cur]; });
        int sumB = accumulate(vb.begin(), vb.end(), 0, [&plays](int acc, int cur){ return acc + plays[cur]; });
        
        return sumA > sumB;
    };
    
    auto comp2 = [&plays](int a, int b) -> bool
    {
        if(plays[a] != plays[b]) return plays[a] > plays[b];
        else return a < b;
    };
    
    sort(v.begin(), v.end(), comp1);
    
    vector<vector<int>> v1;
    transform(v.begin(), v.end(), back_inserter(v1), [](auto el){return el.second;});
    for(auto& el : v1)
    {
        sort(el.begin(), el.end(), comp2);
        
        answer.push_back(el[0]);
        if(el.size() > 1) answer.push_back(el[1]);
    }

    return answer;
}