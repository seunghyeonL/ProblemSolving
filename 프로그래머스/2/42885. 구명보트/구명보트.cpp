#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    auto left = people.begin();
    auto right = people.end() - 1;

    while (left <= right)
    {
        int boat = 0;
        boat += *(right--);
        
        if (left <= right && boat + *left <= limit) 
            boat += *(left++);

        answer++;
    }

    return answer;
}