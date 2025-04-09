#include <bits/stdc++.h> // GCC 전용, 모든 표준 헤더 포함

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); // C++의 std::cin과 std::cout의 동기화 끊기
    cin.tie(nullptr);            // 입출력 독립 실행
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    unordered_map<char, int> um;

    string word;
    cin >> word;

    for (char c : word)
    {
        um[c]++;
    }

    string result;

    for (char c = 'a'; c <= 'z'; c++)
    {
        result += to_string(um[c]);
        result.push_back(' ');
    }
    result.pop_back();

    cout << result;

    // inputFileStream.close();

    return 0;
}
