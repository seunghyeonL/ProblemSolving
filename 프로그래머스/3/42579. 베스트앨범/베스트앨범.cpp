#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>


using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    using T = tuple<string, int, int>; // 장르, 재생횟수, 고유번호

    vector<int> answer;
    int size = plays.size();

    unordered_map<string, int> um; // 장르, 재생횟수
    vector<T> v(size);

    for (int i = 0; i < size; i++)
    {
        v[i] = {genres[i], plays[i], i};
    }

    for (int i = 0; i < size; i++)
    {
        um[genres[i]] += plays[i];
    }

    auto comp = [&](const T &a, const T &b)
    {
        auto [g1, p1, i1] = a;
        auto [g2, p2, i2] = b;

        if (g1 == g2 && p1 == p2)
        {
            return i1 < i2;
        }
        else if (g1 == g2)
        {
            return p1 > p2;
        }
        else
        {
            return um[g1] > um[g2];
        }
    };

    sort(v.begin(), v.end(), comp);

    unordered_map<string, int> used;
    for (auto [genre, play, idx] : v)
    {
        if (used.find(genre) == used.end() || used[genre] < 2)
        {
            answer.push_back(idx);
            used[genre]++;
        }
    }

    return answer;
}
