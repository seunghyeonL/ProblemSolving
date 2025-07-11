#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 5000;
    int size = info.size();
    
    // A 도둑 흔적 합 < n && B 도둑 흔적 합 < m
    // 인 경우 중 A 도둑 흔적 합이 최소인 경우 찾기
    
    vector<vector<vector<bool>>> visited(size, vector<vector<bool>>(n, vector<bool>(m, false))); // idx, accA, accB
    
    function<void(int, int, int)> steal = [&](int idx, int accA, int accB) -> void
    {
        if (idx == size)
        {
            answer = min(answer, accA);
            return;
        }
        
        if (visited[idx][accA][accB])
        {
            return;
        }
        visited[idx][accA][accB] = true;
        
        if (accA + info[idx][0] < n && accA + info[idx][0] < answer)
        {
            accA += info[idx][0];
            steal(idx + 1, accA, accB);
            accA -= info[idx][0];
        }
        
        if (accB + info[idx][1] < m)
        {
            accB += info[idx][1];
            steal(idx + 1, accA, accB);
            accB -= info[idx][1];
        }
    };
    
    sort(info.begin(), info.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] > b[0]; });
    
    steal(0, 0, 0);
    if (answer == 5000)
    {
        answer = -1;
    }
    
    return answer;
}