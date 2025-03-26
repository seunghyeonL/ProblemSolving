#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
    int ticketNumbers = tickets.size();
    // ticket 사용여부
    vector<bool> isUsed(ticketNumbers, false);

    // pair로 만든 tickets
    vector<pair<string, string>> ptickets;
    for (auto ticket : tickets)
    {
        ptickets.push_back({ticket[0], ticket[1]});
    }
    // 알파벳 빠른거 부터 탐색하도록 sort
    sort(ptickets.begin(), ptickets.end());

    // 도시 방문 기록
    vector<string> history{"ICN"};

    // 티켓 인접리스트 -> node: ticketIndex, edge: possible ticket to use next
    vector<vector<int>> ticketAdjList(ticketNumbers);
    for (int i = 0; i < ticketNumbers; i++)
    {
        auto [iStart, iDest] = ptickets[i];
        for (int j = 0; j < ticketNumbers; j++)
        {
            auto [jStart, jDest] = ptickets[j];
            if (iDest == jStart)
            {
                ticketAdjList[i].push_back(j);
            }
        }
    }

    function<bool(int, int)> dfs = [&](int curTicketIdx, int depth)
    {
        if (depth == ticketNumbers)
        {
            return true;
        }

        for (int nextTicketIdx : ticketAdjList[curTicketIdx])
        {
            auto [start, dest] = ptickets[nextTicketIdx];
            if (!isUsed[nextTicketIdx])
            {
                isUsed[nextTicketIdx] = true;
                history.push_back(dest);

                if (dfs(nextTicketIdx, depth + 1))
                    return true;

                isUsed[nextTicketIdx] = false;
                history.pop_back();
            }
        }
        return false;
    };

    for (int i = 0; i < ticketNumbers; i++)
    {
        auto [start, dest] = ptickets[i];
        if (start == "ICN")
        {
            history.push_back(dest);
            isUsed[i] = true;
            
            if(dfs(i, 1)) break;
            
            isUsed[i] = false;
            history.pop_back();
        }
    }

    return history;
}