#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false); // C++의 std::cin과 std::cout의 동기화 끊기
    cin.tie(nullptr);            // 입출력 독립 실행
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    long long K, N;
    cin >> K >> N;

    vector<long long> lines(K);
    long long maxLineLength = 0;

    for (long long i = 0; i < K; i++)
    {
        cin >> lines[i];
        if (lines[i] > maxLineLength)
            maxLineLength = lines[i];
    }

    long long begin = 1;
    long long end = maxLineLength;

    auto getLineNumByLength = [&](long long length)
    {
        long long result = 0;

        for (long long line : lines)
        {
            result += line / length;
        }

        return result;
    };

    while (begin <= end)
    {
        long long mid = (begin + end) / 2;
        if (getLineNumByLength(mid) < N)
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    cout << end;

    // inputFileStream.close();

    return 0;
}

