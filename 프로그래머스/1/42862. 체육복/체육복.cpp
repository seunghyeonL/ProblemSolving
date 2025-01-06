#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1);
    
    sort(reserve.begin(), reserve.end());

    for(int num : reserve) {
        int idx = num - 1;
        students[idx] = 2;
    }
    
    for (int num : lost) {
        int idx = num - 1;
        students[idx]--;
    }
    
    for (int num : reserve) {
        int idx = num - 1;
        
        if(students[idx] == 1) {
            continue;
        }
        
       if (idx > 0 && students[idx - 1] == 0) {
            students[idx - 1]++;
            students[idx]--;
        } else if (idx < n - 1 && students[idx + 1] == 0) {
            students[idx + 1]++;
            students[idx]--;
        }
    }
    
    for(int num : students) {
        answer += num ? 1 : 0;
    }
    
    return answer;
}