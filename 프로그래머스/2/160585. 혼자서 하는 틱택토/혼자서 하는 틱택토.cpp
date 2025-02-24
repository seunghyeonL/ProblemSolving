#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> board) {
    int ONum = 0, XNum = 0;
    string CompleteLine = "";

    for (string row : board) {
        for (char c : row) {
            if (c == 'O') ONum++;
            if (c == 'X') XNum++;
        }
    }

    if (ONum != XNum && ONum != XNum + 1) return 0;

    vector<string> lines = { board[0], board[1], board[2] };
    
    for (int i = 0; i < 3; i++) {
        string col = { board[0][i], board[1][i], board[2][i] };
        lines.push_back(col);
    }

    lines.push_back({ board[0][0], board[1][1], board[2][2] });
    lines.push_back({ board[0][2], board[1][1], board[2][0] });

    int oWin = 0, xWin = 0;

    for (string line : lines) {
        if (line == "OOO") oWin++;
        if (line == "XXX") xWin++;
    }

    if (oWin > 0 && xWin > 0) return 0;
    if (oWin > 0 && ONum != XNum + 1) return 0;
    if (xWin > 0 && ONum != XNum) return 0;

    return 1;
}
