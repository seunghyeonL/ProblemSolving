#include <bits/stdc++.h>
using namespace std;

string S, E, Q;
unordered_map<string, vector<int>> um;

int s2time(const string &s)
{
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> S >> E >> Q;
    int st = s2time(S);
    int et = s2time(E);
    int qt = s2time(Q);

    string chatTime;
    string nick;
    while (cin >> chatTime >> nick)
    {
        um[nick].push_back(s2time(chatTime));
    }

    int answer = 0;
    for (auto [nick, ctArr] : um)
    {
        bool startAttend = false;
        bool endAttend = false;

        for (int ct : um[nick])
        {
            if (ct <= st)
            {
                startAttend = true;
            }

            if (ct >= et && ct <= qt)
            {
                endAttend = true;
            }
        }

        if (startAttend && endAttend)
        {
            answer++;
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}