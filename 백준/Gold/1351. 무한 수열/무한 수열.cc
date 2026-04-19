#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        dp
        N이 너무 커서
        top down을 쓰고
        vector말고 필요한 부분만 unordered_map으로 저장하자
    */

    long long N, P, Q;
    cin >> N >> P >> Q;

    unordered_map<long long, long long> memo; // i, Ai
    memo[0] = 1;

    function<long long(long long)> solveRec = [&](long long i)
    {
        if (memo.count(i))
            return memo[i];

        return memo[i] = solveRec(i / P) + solveRec(i / Q);
    };

    cout << solveRec(N) << '\n';

    // inputFileStream.close();
    return 0;
}
