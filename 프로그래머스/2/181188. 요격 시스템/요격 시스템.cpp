#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets)
{
    // Prints< vector<vector<int>>, Prints<vector<int>> > prints;
    // greedy
    // (begin, end] 이렇게 개구간 폐구간으로 보고
    // end순으로 정렬해서 앞에꺼부터 end 지점에 미사일을 쏘고 겹치는거 없애가기
    // using Vi = vector<int>;

    int answer = 0;

    struct Comp
    {
        bool operator()(const vector<int> &a, const vector<int> &b) const
        {
            return a[1] < b[1];
        }
    };

    sort(targets.begin(), targets.end(), Comp());

    int missile = -1;
    for (const auto &target : targets)
    {
        if (target[0] >= missile)
        {
            answer++;
            missile = target[1];
        }
    }

    return answer;
}