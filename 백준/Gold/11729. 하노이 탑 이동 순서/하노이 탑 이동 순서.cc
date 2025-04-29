#include <bits/stdc++.h>

using namespace std;

int hanoi(int from, int to, int n, vector<pair<int, int>>& history)
{
    if (n == 1)
    {
        history.emplace_back(from, to);
        return 1;
    }
        
    int temp{};
    for (int i = 1 ; i <= 3 ; i++)
    {
        if (i != from && i != to)
        {
            temp = i;
            break;
        }
    }

    int run1 = hanoi(from, temp, n - 1, history);
    history.emplace_back(from, to);
    int run2 = hanoi(temp, to, n - 1, history);
    return run1 + 1 + run2;
};

int main(int argc, char const* argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> history;
    
    int N;
    cin >> N;
    
    cout << hanoi(1, 3, N, history) << '\n';

    string result{};
    for (auto p : history)
    {
        result += to_string(p.first);
        result += ' ';
        result += to_string(p.second);
        result += '\n';
    }
    result.pop_back();
    cout << result;
    
    // ifstream inputFileStream("input.txt");
    //
    // inputFileStream.close();
    
    return 0;
}
