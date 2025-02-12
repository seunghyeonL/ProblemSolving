#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

double getPartialArea(int a, int b, const vector<int>& collatz) {
    double result = 0;
    int n = collatz.size();
    
    int begin = a;
    int end = n + b;
    double cur = collatz[begin];
    
    for(int i = begin + 1; i < end ; i++)
    {
        double next = collatz[i];
        result += cur * 1 + (next - cur) * 1/2;
        // cout << "cur: " << cur << " next: " << next << " result: " << result << '\n';
        
        cur = next;
    }
    
    if(begin >= end) result = -1;
    // cout << "begin: " << begin << " end: " << end << " result: " << result << '\n';
    
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int size = ranges.size();
    
    vector<int> collatz{k};
    while(k > 1)
    {
        
        if (k % 2 == 0) k /= 2;
        else 
        {
            k *= 3;
            k += 1;
        }
        collatz.push_back(k);
    }
    
    // Prints<vector<int>>()(collatz);
    
    transform(ranges.begin(), ranges.end(), back_inserter(answer), [&collatz](auto el){
        int a = el[0], b = el[1];
        return getPartialArea(a, b, collatz);
    });
    
    return answer;
}