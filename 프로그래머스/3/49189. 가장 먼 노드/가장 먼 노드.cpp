#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDist = 0;
    
    vector<int> isVisited(n + 1, -1);
    vector<vector<int>> adjList(n + 1);
    
    for(auto el : edge)
    {
        adjList[el[0]].push_back(el[1]);
        adjList[el[1]].push_back(el[0]);
    }
    
    queue<int> q;
    q.push(1);
    isVisited[1] = 0;
    
    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        for(int nextNode : adjList[curNode])
        {
            if(isVisited[nextNode] != -1) continue;
            
            q.push(nextNode);
            isVisited[nextNode] = isVisited[curNode] + 1;
            
            if(isVisited[nextNode] > maxDist) 
            {
                maxDist = isVisited[nextNode];
                answer = 1;
            }
            else
            {
                answer++;
            }
        }
    }
    
    return answer;
}