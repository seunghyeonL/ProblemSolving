#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    int size = sequence.size();
    vector<int> answer{0, size - 1};
    int idx1 = 0, idx2 = 0;
    
    vector<int> partialSum(size);
    partialSum[0] = 0;
    for(int i = 0 ; i < size ; i++) 
    {
        partialSum[i + 1] = partialSum[i] + sequence[i];
    }
    
    while(idx1 <= idx2 && idx2 < size) 
    {
        if(partialSum[idx2 + 1] - partialSum[idx1] < k) 
        {
            ++idx2;
        }
        else if(partialSum[idx2 + 1] - partialSum[idx1] > k) 
        {
            ++idx1;    
        }
        else  
        {
            if(answer[1] - answer[0] > idx2 - idx1) 
            {
                answer[0] = idx1;
                answer[1] = idx2;
            }
            
            if(idx1 < idx2) 
            {
                ++idx1;     
            }
            else {
                break;
            }
        }
    }
    
    return answer;
}
