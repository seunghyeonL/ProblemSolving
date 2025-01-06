#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int imin = 50;
    int imax = 0;
    int jmin = 50;
    int jmax = 0;

    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                imin = imin > i ? i : imin;
                imax = imax < i ? i : imax;
                jmin = jmin > j ? j : jmin;
                jmax = jmax < j ? j : jmax;
            }
        }
    }

    answer.push_back(imin);
    answer.push_back(jmin);
    answer.push_back(imax + 1);
    answer.push_back(jmax + 1);

    return answer;
}