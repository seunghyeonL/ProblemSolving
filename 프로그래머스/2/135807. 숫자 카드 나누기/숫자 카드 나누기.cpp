#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    // cout << "gcdA: " << gcdA << " gcdB: " << gcdB << " g: " << g << '\n';

    int gcdA =
        accumulate(arrayA.begin() + 1, arrayA.end(), arrayA[0], gcd<int, int>);
    int gcdB =
        accumulate(arrayB.begin() + 1, arrayB.end(), arrayB[0], gcd<int, int>);

    for (int a : arrayA)
    {
        if (a % gcdB == 0)
        {
            gcdB = 0;
            break;
        }
    }

    for (int b : arrayB)
    {
        if (b % gcdA == 0)
        {
            gcdA = 0;
            break;
        }
    }

    answer = max(gcdA, gcdB);

    return answer;
}
