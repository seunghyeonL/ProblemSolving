#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    // Kadane's algorithm
    
    using ll = long long;

    int size = sequence.size();
    
    ll maxPartSum1 = 0;
    ll maxCurrentEnding1 = 0;
    
    int mul = 1;
    for (int& el : sequence)
    {
        mul *= -1;
        el *= mul;
    }
    
    for (int i = 0 ; i < size ; i++)
    {
        maxCurrentEnding1 = max(ll(sequence[i]), maxCurrentEnding1 + sequence[i]);
        maxPartSum1 = max(maxCurrentEnding1, maxPartSum1);
    }
    
    ll maxPartSum2 = 0;
    ll maxCurrentEnding2 = 0;
    
    for (int& el : sequence)
    {
        el *= -1;
    }
    
    for (int i = 0 ; i < size ; i++)
    {
        maxCurrentEnding2 = max(ll(sequence[i]), maxCurrentEnding2 + sequence[i]);
        maxPartSum2 = max(maxCurrentEnding2, maxPartSum2);
    }
    
    return max(maxPartSum1, maxPartSum2);
}