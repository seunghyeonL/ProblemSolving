#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    priority_queue<char> xq;
    priority_queue<char> yq;

    for (int i = 0; i < X.size(); i++) {
        xq.push(X[i]);
    }

    for (int i = 0; i < Y.size(); i++) {
        yq.push(Y[i]);
    }

    while (!xq.empty() && !yq.empty()) {
        if (xq.top() == yq.top()) {
            answer += xq.top();
            xq.pop();
            yq.pop();
        } else if (xq.top() > yq.top()) {
            xq.pop();
        } else if (xq.top() < yq.top()) {
            yq.pop();
        }
    }

    if (answer[0] == '0') {
        answer = "0";
    }

    if (answer.size() == 0) {
        answer = "-1";
    }

    return answer;
}