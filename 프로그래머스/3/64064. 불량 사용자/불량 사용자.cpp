#include <string>
#include <vector>
#include <set>
#include <functional>
#include <cassert>

using namespace std;


int solution(vector<string> user_id, vector<string> banned_id)
{
    int size = user_id.size();
    int trieSize = 0;
    for (string &id : user_id)
    {
        trieSize += id.size();
    }

    // 숫자 : 0 ~ 9 알파벳 : 10 ~ 35
    auto char2Idx = [](char c) -> int
    {
        if (c >= '0' && c <= '9')
            return c - '0';

        if (c >= 'a' && c <= 'z')
            return 10 + (c - 'a');

        assert(0);
    };

    auto idx2Char = [](int i) -> char
    {
        if (i >= 0 && i <= 9)
        {
            return '0' + i;
        }
        else if (i <= 35)
        {
            return 'a' + i - 10;
        }

        assert(0);
    };

    // trie[노드][알파벳 or 숫자] : 다음노드
    vector<vector<int>> trie(trieSize + 1, vector<int>(36));
    vector<bool> endNode(trieSize + 1, false);
    int unused = 1;

    // insert
    for (string id : user_id)
    {
        int cur = 0;

        for (int i = 0; i < id.size(); i++)
        {
            int n = char2Idx(id[i]);
            if (trie[cur][n])
            {
                cur = trie[cur][n];
            }
            else
            {
                trie[cur][n] = unused++;
                cur = trie[cur][n];
            }
        }

        endNode[cur] = true;
    }

    set<set<string>> results;
    vector<vector<string>> v;
    v.reserve(banned_id.size());

    function<void(const string &, string, int, vector<string> &)> dfs =
        [&](const string &bid, string cur, int cv, auto &posBanIds)
    {
        int i = cur.size();
        if (i == bid.size())
        {
            if (endNode[cv]) posBanIds.push_back(cur);
            
            return;
        }

        char c = bid[i];
        if (c != '*')
        {
            if (int nv = trie[cv][char2Idx(c)])
            {
                dfs(bid, cur + c, nv, posBanIds);
            }
        }
        else
        {
            for (int i = 0; i < 36; i++)
            {
                int nv = trie[cv][i];
                if (!nv)
                    continue;

                dfs(bid, cur + idx2Char(i), nv, posBanIds);
            }
        }
    };

    for (string bid : banned_id)
    {
        vector<string> posBanIds;
        dfs(bid, "", 0, posBanIds);
        v.push_back(posBanIds);
    }

    set<string> curSet;
    function<void(int)> resultRec = [&](int idx)
    {
        if (idx == banned_id.size())
        {
            results.insert(curSet);
            return;
        }

        for (string str : v[idx])
        {
            if (curSet.count(str))
                continue;

            curSet.insert(str);
            resultRec(idx + 1);
            curSet.erase(str);
        }
    };

    // Printc<vector<vector<string>>, Printc<vector<string>>>()(v);

    resultRec(0);

    return results.size();
}