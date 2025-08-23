#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int waveNum = enemy.size();
    
    priority_queue<int, vector<int>, greater<int>> pq(enemy.begin(), enemy.begin() + min(k, waveNum));
    
    // for(int i = 0 ; i < min(k, waveNum) ; i++) 
    // {
    //     pq.push(enemy[i]);
    // }
    answer = min(k, waveNum);
    
    
    
    for(int i = min(k, waveNum) ; i < waveNum ; i++)
    {
        int cheatMin = pq.top();
        
        // cout << "i: " << i << " " << " cheatMin: " << cheatMin << " " << " enemy[i] " << enemy[i] << '\n';
        
        if(cheatMin < enemy[i])
        {
            pq.pop();
            n -= cheatMin;
            pq.push(enemy[i]);
        }
        else
        {
            n -= enemy[i];
        }
        
        if (n < 0)
        {
            break;
        }
        
        answer = i + 1;
    }
    
    return answer;
}