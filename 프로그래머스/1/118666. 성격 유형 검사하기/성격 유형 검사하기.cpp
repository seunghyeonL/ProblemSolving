#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    int RT = 0;
    int CF = 0;
    int JM = 0;
    int AN = 0;

    for (int i = 0; i < survey.size(); i++) {
        if (survey[i] == "RT") {
            RT += choices[i] - 4;
        } else if (survey[i] == "TR") {
            RT += 4 - choices[i];
        } else if (survey[i] == "CF") {
            CF += choices[i] - 4;
        } else if (survey[i] == "FC") {
            CF += 4 - choices[i];
        } else if (survey[i] == "JM") {
            JM += choices[i] - 4;
        } else if (survey[i] == "MJ") {
            JM += 4 - choices[i];
        } else if (survey[i] == "AN") {
            AN += choices[i] - 4;
        } else if (survey[i] == "NA") {
            AN += 4 - choices[i];
        }
    }

    answer += RT <= 0 ? "R" : "T";
    answer += CF <= 0 ? "C" : "F";
    answer += JM <= 0 ? "J" : "M";
    answer += AN <= 0 ? "A" : "N";

    return answer;
}