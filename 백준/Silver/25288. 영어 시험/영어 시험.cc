#include <bits/stdc++.h>
using namespace std;    

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
    3
    abc

    abcabcabc

    각 알파벳이 N번 나오는 경우가 최소
    문자열을 N번 붙인건 항상 정답이고 길이는 최소
    */

    int N;
    cin >> N;

    string cand;
    cin >> cand;

    for (int i = 0; i < N; i++)
        cout << cand;

    // inputFileStream.close();
    return 0;
}