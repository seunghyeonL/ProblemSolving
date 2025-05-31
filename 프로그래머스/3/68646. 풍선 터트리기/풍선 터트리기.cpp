#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int size = a.size();
    int answer = size;
    
    // -16 27 65 -2 58 -92 -71 -68 -61 -33
    // -16             -92 -71 -68 -61 -33
    
    // 자신의 좌측, 우측 모두 자신보다 작은 수가 존재할 경우 남길 수 없다.
    
    vector<int> leftMin(size);
    vector<int> rightMin(size);
    
    leftMin[0] = a[0];
    rightMin[size - 1] = a[size - 1];
    
    for(int i = 1 ; i < size ; i++)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
        rightMin[size - 1 - i] = min(rightMin[size - i], a[size - 1 - i]);
    }
    
    for(int i = 0 ; i < size ; i++)
    {
        if(leftMin[i] < a[i] && rightMin[i] < a[i])
        {
            answer--;
        }
    }
    
    return answer;
}