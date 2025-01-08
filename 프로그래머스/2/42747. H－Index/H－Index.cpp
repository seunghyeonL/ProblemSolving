#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer{};
    int paperNum{};

    while(true) {
        answer++;
        paperNum = 0;

        for(int n : citations) {
            if(n >= answer) {
                paperNum++;
            }
        } 

        if(answer == paperNum) {
            break;
        } else if(answer > paperNum) {
            answer--;
            break;
        }
    } 

    return answer;
}