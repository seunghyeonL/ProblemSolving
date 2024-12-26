#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(vector<string> seoul) {
    auto kimIt = find(seoul.begin(), seoul.end(), "Kim");
    stringstream ss;
    ss << "김서방은 " << distance(seoul.begin(), kimIt) << "에 있다";
    return ss.str();
    
}