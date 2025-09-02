#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <unordered_set>

using namespace std;

vector<string> split(string str)
{
    istringstream iss(str);
    vector<string> result;

    string s;
    while (iss >> s)
    {
        result.push_back(s);
    }

    return result;
}

string join(vector<string> v)
{
    string result;

    for (string s : v)
    {
        result += s;
        result.push_back(' ');
    }
    result.pop_back();

    return result;
}

vector<string> solution(vector<string> expressions)
{
    vector<string> answer;
    int size = expressions.size();
    // Printc<set<int>> printc;
    // Printc<unordered_set<int>> printus;

    /*
        X가 아닌 문자열부터 앞에 배치하고
        하나씩 계산하면서 2 ~ 9진법 중 불가능한 진법을 쳐내기
        그리고 X인 문자열에서 남은 가능한 진법들을 대입시켜본 후 다른게 있으면
       ?로, 다 같으면 그 숫자로
    */

    stable_partition(expressions.begin(), expressions.end(),
                     [](string s) { return s.back() != 'X'; });

    // 가능한 진법 모음
    set<int> nSet{2, 3, 4, 5, 6, 7, 8, 9};

    vector<vector<string>> splitedExp(size);

    // splitedExp에 쪼개서 넣기
    for (int i = 0; i < size; i++)
    {
        const vector<string> &sp = splitedExp[i] = split(expressions[i]);

        for (int i = 0; i < 5; i += 2)
        {
            for (char c : sp[i])
            {
                // 숫자 n이 사용되면 n진법 이하의 진법으로는 표현 불가
                if (auto it = nSet.find(c - '0'); it != nSet.end())
                {
                    nSet.erase(nSet.begin(), next(it));
                }
            }
        }
    }

    auto nstr2Decimal = [&](string str, int n)
    {
        int result = 0;
        for (char c : str)
        {
            result = n * result + (c - '0');
        }

        return result;
    };

    auto decimal2nstr = [&](int num, int n)
    {
        string result{};

        while (num > 0)
        {
            result.push_back('0' + num % n);
            num /= n;
        }

        reverse(result.begin(), result.end());

        if (result.empty())
            result.push_back('0');

        return result;
    };

    auto operatePlus = [&](const string &op1, const string &op2,
                           const string &res, int n,
                           unordered_set<int> &removed)
    {
        // n진법이라 치고 계산했을때 맞는지 확인
        if (nstr2Decimal(op1, n) + nstr2Decimal(op2, n) != nstr2Decimal(res, n))
        {
            removed.insert(n);
        }
    };

    auto operateMinus = [&](const string &op1, const string &op2,
                            const string &res, int n,
                            unordered_set<int> &removed)
    {
        // n진법이라 치고 계산했을때 맞는지 확인
        if (nstr2Decimal(op1, n) - nstr2Decimal(op2, n) != nstr2Decimal(res, n))
        {
            removed.insert(n);
        }
    };

    auto operatePlusX = [&](const string &op1, const string &op2, int n,
                            string &result) -> bool
    {
        // n진법이라 치고 계산했을때 결과가 result랑 같은지 확인
        if (result.empty())
        {
            result =
                decimal2nstr(nstr2Decimal(op1, n) + nstr2Decimal(op2, n), n);
            return true;
        }

        if (result !=
            decimal2nstr(nstr2Decimal(op1, n) + nstr2Decimal(op2, n), n))
        {
            return false;
        }

        return true;
    };

    auto operateMinusX = [&](const string &op1, const string &op2, int n,
                             string &result) -> bool
    {
        // n진법이라 치고 계산했을때 결과가 result랑 같은지 확인
        if (result.empty())
        {
            result =
                decimal2nstr(nstr2Decimal(op1, n) - nstr2Decimal(op2, n), n);
            return true;
        }

        if (result !=
            decimal2nstr(nstr2Decimal(op1, n) - nstr2Decimal(op2, n), n))
        {
            return false;
        }

        return true;
    };

    auto operate = [&](vector<string> &splited)
    {
        char op = splited[1][0];

        if (op == '+' && splited[4][0] != 'X')
        {
            unordered_set<int> removed;
            for (int n : nSet)
            {
                operatePlus(splited[0], splited[2], splited[4], n, removed);
            }

            for (int n : removed)
            {
                nSet.erase(n);
            }
        }
        else if (op == '+' && splited[4][0] == 'X')
        {
            string result{};

            for (int n : nSet)
            {
                if (!operatePlusX(splited[0], splited[2], n, result))
                {
                    splited[4][0] = '?';
                    break;
                }
            }

            if (splited[4] != "?")
                splited[4] = result;

            answer.push_back(join(splited));
        }
        else if (op == '-' && splited[4][0] != 'X')
        {
            unordered_set<int> removed;
            for (int n : nSet)
            {
                operateMinus(splited[0], splited[2], splited[4], n, removed);
            }

            for (int n : removed)
            {
                nSet.erase(n);
            }
        }
        else if (op == '-' && splited[4][0] == 'X')
        {
            string result{};

            for (int n : nSet)
            {
                if (!operateMinusX(splited[0], splited[2], n, result))
                {
                    splited[4] = "?";
                    break;
                }
            }

            if (splited[4] != "?")
                splited[4] = result;

            answer.push_back(join(splited));
        }
    };

    for (auto splited : splitedExp)
    {
        operate(splited);
    }

    return answer;
}
