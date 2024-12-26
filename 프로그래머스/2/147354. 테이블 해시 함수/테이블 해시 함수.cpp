#include <algorithm>
#include <fstream> // 파일 입출력
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    col -= 1;
    row_begin -= 1;
    row_end -= 1;

    function<bool(vector<int>, vector<int>)> compare =
        [col](vector<int> a, vector<int> b) -> bool {
        return a[col] != b[col] ? (a[col] < b[col]) : a[0] > b[0];
    };

    sort(data.begin(), data.end(), compare);

    int index = row_begin;
    vector<int> S_IVec(row_end - row_begin + 1);
    transform(data.begin() + row_begin, data.begin() + row_end + 1,
              S_IVec.begin(), [&index](auto row) -> auto {
                  int S_i = accumulate(row.begin(), row.end(), 0,
                                       [&index](auto acc, auto cur) -> auto {
                                           return acc + (cur % (index + 1));
                                       });
                  index++;
                  return S_i;
              });

    return accumulate(S_IVec.begin() + 1, S_IVec.end(), *S_IVec.begin(),
                      [](auto acc, auto cur) -> auto { return acc ^ cur; });
}