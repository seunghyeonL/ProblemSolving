#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); // C++의 std::cin과 std::cout의 동기화 끊기
    cin.tie(nullptr);            // 입출력 독립 실행
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> damages(N);
    vector<int> happys(N);
    int hp = 100;
    int maxPleasure = 0;
    int pleasure = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> damages[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> happys[i];
    }

    function<void(int)> run = [&](int idx) -> void
    {
        if (idx == N)
        {
            maxPleasure = max(pleasure, maxPleasure);
            return;
        }

        if (damages[idx] < hp)
        {
            hp -= damages[idx];
            pleasure += happys[idx];
            run(idx + 1);
            pleasure -= happys[idx];
            hp += damages[idx];
        }

        run(idx + 1);
    };

    run(0);

    cout << maxPleasure;

    // inputFileStream.close();

    return 0;
}
