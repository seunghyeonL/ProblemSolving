#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // N개의 정류장
    // 대학교 A, B, C, D, E마다 X개의 버스 노선
    // 각 노선끼리 인접 행렬 busRoadAdjMat
    // ABCDE -> 01234

    int N, X;
    cin >> N >> X;

    int roadSize = 5 * X + 1;
    const int INF = 1e9;
    vector<vector<int>> busRoadAdjMat(roadSize, vector<int>(roadSize, INF));

    for (int i = 0 ; i < roadSize ; i++)
    {
        busRoadAdjMat[i][i] = 0;
    }
    
    vector<vector<int>> stationBusRoads(N + 1);
    vector<vector<int>> busRoadStations(roadSize);
    
    auto connectBusRoads = [&](const vector<int>& busRoads)
    {
        int size = busRoads.size();
        for (int i = 0 ; i < size - 1 ; i++)
        {
            for (int j = i + 1 ; j < size ; j++)
            {
                busRoadAdjMat[busRoads[i]][busRoads[j]] = 1;
                busRoadAdjMat[busRoads[j]][busRoads[i]] = 1;
            }
        }
    };

    auto findMinTransfer = [&](const vector<int>& startBusRoads, const vector<int>& destBusRoads)
    {
        int minTransfer = INF;
        for (int startBusRoad : startBusRoads)
        {
            for (int destBusRoad : destBusRoads)
            {
                minTransfer = min(minTransfer, busRoadAdjMat[startBusRoad][destBusRoad]);
            }
        }

        return minTransfer;
    };

    auto isInSameBusRoad = [&](int u, int v)
    {
        for (auto busRoad : stationBusRoads[u])
        {
            for (auto station : busRoadStations[busRoad])
            {
                if (station == v) return true;
            }
        }

        return false;   
    };
    
    for (int i = 1 ; i <= N ; i++)
    {
        vector<int> busRoads(5);
        for (int n = 0 ; n < 5 ; n++)
        {
            int x;
            cin >> x;
            busRoads[n] = n * X + x;
            busRoadStations[busRoads[n]].push_back(i);
        }

        connectBusRoads(busRoads);
        stationBusRoads[i] = std::move(busRoads);
    }
    
    for (int k = 1 ; k < roadSize ; k++)
    {
        for (int i = 1 ; i < roadSize ; i++)
        {
            for (int j = 1 ; j < roadSize ; j++)
                busRoadAdjMat[i][j] = min(busRoadAdjMat[i][j], busRoadAdjMat[i][k] + busRoadAdjMat[k][j]);
        }
    }
    
    int Q;
    cin >> Q;

    for (int i = 0 ; i < Q ; i++)
    {
        int u, v;
        cin >> u >> v;

        if (isInSameBusRoad(u, v)) cout << 1 << '\n';
        else
        {
            int mintransfer = findMinTransfer(stationBusRoads[u], stationBusRoads[v]);
            if (mintransfer == INF) cout << -1 << '\n';
            else cout << mintransfer + 1 << '\n';
        }
    }
    
    // inputFileStream.close();
    return 0;
}