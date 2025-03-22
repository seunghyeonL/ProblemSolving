#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    int size = 9;
    vector<int> numbers(9);

    for (int i = 0 ; i < 9 ; i++)
    {
        cin >> numbers[i];
    }

    vector<int> isPicked {1, 1, 1, 1, 1, 1, 1, 0, 0};

    do
    {
        int sum = 0;
        for (int i = 0 ; i < size ; i++)
        {
            if (isPicked[i])
            {
                sum += numbers[i];
            }
        }
        
        if (sum == 100) break;
    }
    while (prev_permutation(isPicked.begin(), isPicked.end()));

    for (int i = 0 ; i < size ; i++)
    {
        if (isPicked[i]) cout << numbers[i] << '\n';
    }
    
    return 0;
}