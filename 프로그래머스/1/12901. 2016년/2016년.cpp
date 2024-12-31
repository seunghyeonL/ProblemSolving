#include <string>
#include <vector>

using namespace std;

int getDateDiff(int m1, int d1, int m2, int d2) {
    int dayNumbers[13]{
        0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int result = 0;

    if (m1 == m2) {
        result += d2 - d1;
        return result;
    }

    result += dayNumbers[m1] - d1;
    for (int i = m1 + 1 ; i < m2 ; i++) {
        result += dayNumbers[i];
    }
    result += d2;
    return result;
}

string solution(int a, int b) {
    string answer = "";
    string dayNames[7]{
        "FRI",
        "SAT",
        "SUN",
        "MON",
        "TUE",
        "WED",
        "THU"
    };
    
    int dateDiff = getDateDiff(1, 1, a, b);
    
    answer = dayNames[dateDiff % 7];

    return answer;
}
