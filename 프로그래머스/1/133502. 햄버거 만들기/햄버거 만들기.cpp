#include <string>
#include <vector>

using namespace std;

void match(int &answer, vector<int> &v) {
    auto endIt = v.end();

    if (*(endIt - 1) == 1 && *(endIt - 2) == 3 && *(endIt - 3) == 2 &&
        *(endIt - 4) == 1) {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        answer++;

        match(answer, v);
    }
}

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    for (int el : ingredient) {
        v.push_back(el);
        if (v.size() >= 4) {
            match(answer, v);
        }
    }

    return answer;
}