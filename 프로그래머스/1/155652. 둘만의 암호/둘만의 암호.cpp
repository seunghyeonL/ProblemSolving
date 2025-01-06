#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    const int r = 'z' - 'a';

    transform(s.begin(), s.end(), back_inserter(answer),
              [&skip, index](char chr) mutable -> char {
                  int initIndex = index;
                  while (index > 0) {
                      if (chr == 'z') {
                          chr = 'a';
                      } else {
                          chr += 1;
                      }

                      if (skip.find(chr) == string::npos) {
                          index--;
                      }
                  }
                  index = initIndex;
                  return chr;
              });

    return answer;
}