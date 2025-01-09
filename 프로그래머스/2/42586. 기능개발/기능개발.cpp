#include <string>
#include <vector>

using namespace std;
int deploy(int &i, const vector<int> &progresses)
{
    int cnt = 0;
    while (progresses[i] >= 100 && i < progresses.size())
    {
        ++i;
        cnt++;
    }
    return cnt;
}

void work(vector<int> &progresses, const vector<int> speeds)
{
    for (int i = 0; i < progresses.size(); i++)
    {
        progresses[i] += speeds[i];
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int idx = 0;
    while (idx < progresses.size())
    {
        work(progresses, speeds);
        int dn = deploy(idx, progresses);
        if (dn)
        {
            answer.push_back(dn);
        }
    }

    return answer;
}