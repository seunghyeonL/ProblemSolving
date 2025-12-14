#include <bits/stdc++.h>
using namespace std;

// 승리시 +1, 패배, 무승부는 0
// 그리디 
// A를 정렬하고 B도 정렬하고
// A의 가장 작은 수를 B에서 가장 작게 이길 수 있는 경우를 체크

int solution(vector<int> A, vector<int> B) {
    int len = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ans = 0;
    for (int i = 0, j = 0 ; i < len ; i++)
    {
        while (j < len && B[j] <= A[i])
            j++;        
        
        // A[i]를 이길 수 있는 경우가 없음.
        // 현재보다 큰 i에서도 이기는 경우 없음
        if (j == len) 
            break;
        
        j++;
        ans++;
    }
    
    return ans;
}