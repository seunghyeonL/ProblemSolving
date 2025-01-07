#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ') {
    vector<string> result;

    string buffer{};

    for (char chr : str) {
        if (chr == seperator) {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty()) {
        result.push_back(buffer);
    }

    return result;
}


bool isValid(int x, int y, const vector<string> &park) {
    bool result = true;
    if (x < 0 || x >= park.size() || y < 0 || y >= park[0].size()) {
        result = false;
    } else if (park[x][y] == 'X') {
        result = false;
    }

    return result;
}

void move(int &x, int &y, string direction, string distance,
          const vector<string> &park) {
    unordered_map<string, pair<int, int>> moves;
    moves["E"] = {0, 1};
    moves["W"] = {0, -1};
    moves["N"] = {-1, 0};
    moves["S"] = {1, 0};

    int newX = x;
    int newY = y;

    for (int i = 1; i <= stoi(distance); i++) {
        newX += moves[direction].first;
        newY += moves[direction].second;

        if (!isValid(newX, newY, park)) {
            return;
        }
    }

    x = newX;
    y = newY;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int curX{};
    int curY{};

    for (int i = 0; i < park.size(); i++) {
        bool found{false};
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S') {
                curX = i;
                curY = j;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    for (string route : routes) {
        auto splitedRoute = strSplit(route);
        string direction = splitedRoute[0];
        string distance = splitedRoute[1];

        move(curX, curY, direction, distance, park);
    }

    return vector<int>{curX, curY};
}