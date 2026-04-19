#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    int N;
    cin >> N;

    string s0 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    string s1 = "\"재귀함수가 뭔가요?\"\n";
    string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    string s5 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    string s6 = "라고 답변하였지.\n";
    string s7 = "____";

    auto printLine = [&](int n, string s)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s7;
        }
        cout << s;
    };

    function<void(int)> rec = [&](int n)
    {
        printLine(n, s1);

        if (n == N)
        {
            printLine(n, s5);
        }
        else
        {
            printLine(n, s2);
            printLine(n, s3);
            printLine(n, s4);

            rec(n + 1);
        }

        printLine(n, s6);
    };

    cout << s0;
    rec(0);

    // inputFileStream.close();
    return 0;
}


