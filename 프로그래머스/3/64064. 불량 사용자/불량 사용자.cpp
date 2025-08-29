#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <functional>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id)
{
    int size = user_id.size();
    unordered_set<string> userIdSet;
    for (string id : user_id)
    {
        userIdSet.insert(id);
    }

    unordered_map<string, unordered_set<char>> adj;
    for (string id : user_id)
    {
        string tmp{};
        adj[tmp].insert(id[0]);
        tmp += id[0];
        for (int i = 1; i < id.size(); i++)
        {
            adj[tmp].insert(id[i]);
            tmp += id[i];
        }
    }

    function<void(int, string, const string &, unordered_set<string> &)> solve =
        [&](int idx, string cs, const string &bs, auto &us)
    {
        if (idx == bs.size())
        {   
            if (userIdSet.count(cs))
                us.insert(cs);
            return;
        }

        int schar = bs[idx];

        for (auto nchar : adj[cs])
        {
            if (nchar == schar || schar == '*')
                solve(idx + 1, cs + nchar, bs, us);
        }
    };

    int answer = 1;
    vector<unordered_set<string>> v;
    for (string id : banned_id)
    {
        unordered_set<string> us;
        solve(0, string(), id, us);
        v.push_back(us);
    }

    int bsize = banned_id.size();
    set<set<string>> resultSet;
    set<string> curSet;
    function<void(int)> dfs = [&](int idx)
    {
        if (idx == bsize)
        {
            resultSet.insert(curSet);
            return;
        }

        for (auto str : v[idx])
        {
            if (curSet.count(str)) continue;
            curSet.insert(str);
            dfs(idx + 1);
            curSet.erase(str);
        }
    };

    dfs(0);

    return resultSet.size();
}