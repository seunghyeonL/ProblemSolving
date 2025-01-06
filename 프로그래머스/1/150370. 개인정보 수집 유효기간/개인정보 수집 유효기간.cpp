#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ') {
    vector<string> result;

    string buffer{};

    for (char chr : str) {
        if (chr == seperator) {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty()) {
        result.push_back(buffer);
    }

    return result;
}

struct DateStruct {
    int year, month, day;

    DateStruct(int dateValue) {
        year = dateValue / 336;
        dateValue = dateValue % 336;
        month = dateValue / 28 + 1;
        dateValue = dateValue % 28;
        day = dateValue + 1;
    }

    DateStruct(int year, int month, int day)
        : year{year}, month{month}, day{day} {};

    bool operator<(const DateStruct &operand) {
        if (year != operand.year) {
            return year < operand.year;
        } else if (month != operand.month) {
            return month < operand.month;
        } else {
            return day < operand.day;
        }
    }

    int getDateValue() {
        return year * 336 + (month - 1) * 28 + (day - 1);
    }
};

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {

    vector<int> answer;
    unordered_map<string, int> mterms;

    auto todayV = strSplit(today, '.');
    DateStruct todayDate(stoi(todayV[0]), stoi(todayV[1]), stoi(todayV[2]));

    for (string str : terms) {
        auto strV = strSplit(str);
        mterms.insert({strV[0], stoi(strV[1])});
    }

    for (int i = 0; i < privacies.size(); i++) {
        string str = privacies[i];
        auto strV = strSplit(str);
        auto strDate = strSplit(strV[0], '.');

        DateStruct startDate{stoi(strDate[0]), stoi(strDate[1]),
                             stoi(strDate[2])};

        DateStruct lastDate =
            DateStruct(startDate.getDateValue() + mterms[strV[1]] * 28);

        // cout << lastDate.year << " " << lastDate.month << " " << lastDate.day
        //      << '\n';
        // cout << today << '\n';

        if (!(todayDate < lastDate)) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
