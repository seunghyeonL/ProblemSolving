#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> maxVec;
    
    vector<int> minVec; 

    for (auto el : sizes) {
        maxVec.push_back(max(el.at(0), el.at(1)));
        minVec.push_back(min(el.at(0), el.at(1)));
    }

    int width = *max_element(maxVec.begin(), maxVec.end());
    int height = *max_element(minVec.begin(), minVec.end());

    return width * height;
}