#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    int boat = 0;
    int cnt = 0;
    
    while (left <= right)
    {
        while (left <= right && cnt < 2 && boat + people[right] <= limit)
        {
            boat += people[right--];
            cnt++;
        }
        
        while (left <= right && cnt < 2 && boat + people[left] <= limit)
        {
            boat += people[left++];
            cnt++;
        }
        
        answer++;
        boat = 0;
        cnt = 0;
    }
    
    
    return answer;
}