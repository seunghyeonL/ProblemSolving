#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    vector<int> method1{1, 2, 3, 4, 5};
    int size1 = method1.size();
    vector<int> method2{2, 1, 2, 3, 2, 4, 2, 5};
    int size2 = method2.size();
    vector<int> method3{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int size3 = method3.size();

    int size = answers.size();

    vector<int> scores(3, 0);

    for (int i = 0; i < size; i++) {
        if (method1[i % size1] == answers[i]) {
            ++scores[0];
        }
        if (method2[i % size2] == answers[i]) {
            ++scores[1];
        }
        if (method3[i % size3] == answers[i]) {
            ++scores[2];
        }
    }

    for (int i = 0; i < scores.size(); i++) {
        if (!result.empty()) {
            int back = result.back();
            if (scores[back - 1] > scores[i]) {
                continue;
            }

            if (scores[back - 1] < scores[i]) {
                result.clear();
            }
        }

        result.push_back(i + 1);
    }

    return result;
}
