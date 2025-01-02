#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> buffervec;
    priority_queue<int, vector<int>, less<int>> pq{less<int>(), score};
    priority_queue<int, vector<int>, greater<int>> buffer{greater<int>(),
                                                          vector<int>()};

    while (pq.size() > 0) {
        buffer.push(pq.top());
        pq.pop();

        if (buffer.size() == m) {
            answer += buffer.top() * m;
            buffer = priority_queue<int, vector<int>, greater<int>>{
                greater<int>(), vector<int>()};
        }
    }

    return answer;
}