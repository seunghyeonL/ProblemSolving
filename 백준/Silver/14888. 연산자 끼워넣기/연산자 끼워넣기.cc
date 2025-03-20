#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<char> operators;

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                operators.push_back('+');
            else if (i == 1)
                operators.push_back('-');
            else if (i == 2)
                operators.push_back('*');
            else
                operators.push_back('/');
        }
    }

    sort(operators.begin(), operators.end());

    int max = -1 * 1000000000, min = 1000000000;

    auto calculate = [&](int &a, int b, char oper) -> void
    {
        if (oper == '+')
            a += b;
        else if (oper == '-')
            a -= b;
        else if (oper == '*')
            a *= b;
        else if (oper == '/')
            a /= b;
    };

    do
    {
        int cur = v[0];
        for (int i = 0; i < N - 1; i++)
        {
            calculate(cur, v[i + 1], operators[i]);
        }
        if (max < cur)
            max = cur;

        if (min > cur)
            min = cur;
    } while (next_permutation(operators.begin(), operators.end()));

    cout << max << '\n' << min << '\n';

    // inputFileStream.close();

    return 0;
}