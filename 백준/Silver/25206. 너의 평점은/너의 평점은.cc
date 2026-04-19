#include <bits/stdc++.h>
using namespace std;

unordered_map<string, float> grade_map{{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5},
                                       {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0},
                                       {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    string line;
    float sum = 0;
    float total = 0;
    while (getline(cin, line))
    {
        stringstream ss(line);

        string sub;
        float w;
        string grade;
        ss >> sub >> w >> grade;

        if (grade == "P")
            continue;

        sum += w * grade_map[grade];
        total += w;
    }

    cout << sum / total;

    // inputFileStream.close();
    return 0;
}