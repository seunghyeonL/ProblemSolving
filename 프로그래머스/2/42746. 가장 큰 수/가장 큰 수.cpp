#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    
    vector<string> strNumbers;
    
    for(int number : numbers) {
        strNumbers.push_back(to_string(number));
    }

    sort(strNumbers.begin(), strNumbers.end(), [](string a, string b){
        string fstr = a + b;
        string rstr = b + a;
        
        return fstr > rstr;
    });
         

    bool foolZeroFlag = true;
    for (string strNumber : strNumbers)
    {
        if(strNumber != "0")
            foolZeroFlag = false;
        answer += strNumber;
    }

    if (foolZeroFlag)
        return "0";
    return answer;
}