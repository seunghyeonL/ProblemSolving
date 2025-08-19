#include <string>
#include <vector>

using namespace std;

// 남은 여는괄호개수, 닫는괄호개수
int solveRec(int o, int c)
{
    if (o > c) return 0;
    if (o == 0 && c == 0) return 1;
    
    int result = 0;
    
    if (o > 0)
        result += solveRec(o - 1, c);
    
    if (c > 0)
        result += solveRec(o, c - 1);
    
    return result;
}

int solution(int n) {
    return solveRec(n, n);
}