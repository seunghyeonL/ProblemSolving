#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int size = money.size();

    // dp : 0 ~ idx 번 집들을 털때 idx번을 털때의 최대 금액
    // dp1 : 0 ~ idx - 1까지
    // dp2 : 1 ~ idx 까지
    
    vector<int> dp1(size);
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    
    for (int i = 2 ; i < size - 1 ; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }
    
    vector<int> dp2(size);
    dp2[1] = money[1];
    dp2[2] = max(money[1], money[2]);
    
    for (int i = 2 ; i < size ; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }
  
    return max(dp1[size - 2], dp2[size - 1]);
}