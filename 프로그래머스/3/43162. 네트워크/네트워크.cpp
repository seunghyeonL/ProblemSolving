#include <string>
#include <vector>

using namespace std;

void dfs(int curNode, vector<bool>& isVisited, const vector<vector<int>>& computers)
{
    int size = computers.size();
    if(isVisited[curNode]) return;
    isVisited[curNode] = true;
    
    for(int nextNode = 0 ; nextNode < size ; nextNode++)
    {
        if(computers[curNode][nextNode] && !isVisited[nextNode])
        {
            dfs(nextNode, isVisited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int size = computers.size();
    vector<bool> isVisited(size, false);

    for(int node = 0 ; node < size ; node++)
    {
        if(!isVisited[node])
        {
            dfs(node, isVisited, computers);
            answer++;
        }
    }
    
    return answer;
}

