#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    for (int i = 0; i < number.size() - k; i++)
    {
        auto maxIt =
            max_element(number.begin() + i, number.begin() + i + k + 1);

        k = k - distance(number.begin() + i, maxIt);

        number.erase(number.begin() + i, maxIt);
    }

    number.erase(number.end() - k, number.end());

    return number;
}
