#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words)
{
    int answer = 0;
    int size = words.size();

    int trieSize = 0;

    for (string word : words)
    {
        trieSize += word.size();
    }

    int unused = 1;
    vector<vector<int>> trie(trieSize + 1, vector<int>(26, -1));
    vector<bool> endPoints(trieSize + 1, false);
    // 이 노드 포함 하위 word 개수
    vector<int> wordCnt(trieSize + 1, 0);

    auto c2i = [](char c) { return c - 'a'; };

    // insert
    for (string word : words)
    {
        int cur = 0;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];

            if (trie[cur][c2i(c)] != -1)
            {
                cur = trie[cur][c2i(c)];
                continue;
            }

            trie[cur][c2i(c)] = unused;
            cur = unused;
            unused++;
        }
        endPoints[cur] = true;
    }

    // Printc<vector<vector<int>>, Printc<vector<int>>>()(trie);

    function<int(int)> setWordCnt = [&](int cv) -> int
    {
        if (wordCnt[cv])
            return wordCnt[cv];

        int result = 0;

        if (endPoints[cv])
            result++;

        for (int nv : trie[cv])
        {
            if (nv == -1)
                continue;

            result += setWordCnt(nv);
        }

        return wordCnt[cv] = result;
    };

    // cout << unused << '\n';
    setWordCnt(0);

    // Printc<vector<bool>>()(endPoints);
    // Printc<vector<int>>()(wordCnt);

    function<void(int, int)> dfs = [&](int cv, int depth)
    {
        if (cv != 0)
        {
            if (wordCnt[cv] == 1)
            {
                answer += depth;
                return;
            }

            if (endPoints[cv])
            {
                answer += depth;
            }
        }

        for (int nv : trie[cv])
        {
            if (nv == -1)
                continue;

            dfs(nv, depth + 1);
        }
    };

    dfs(0, 0);

    return answer;
}
