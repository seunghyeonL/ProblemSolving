#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int cnt;
int board[9][9];
bool row_chk[9][9] = { false, };
bool col_chk[9][9] = { false, };
bool part_chk[9][9] = { false, };


void recursion(int curr) {
	if (curr == 81 && cnt==0) {
		for (int k = 0; k < 9; k++) {
			for (int l = 0; l < 9; l++) {
				v.push_back(board[k][l]);
			}
		}
		cnt++;
		return;
	}

    if(cnt==1) {
        return;
    }
    
	int i, j;
	bool complete = true;
	int tmp = 0;

	i = curr / 9;
	j = curr % 9;

	if (board[i][j] != 0) 
		recursion(curr + 1);
	else {
		for (int k = 0; k < 9; k++) {
			if (!row_chk[i][k] && !col_chk[j][k] && !part_chk[(i / 3) * 3 + (j / 3)][k]) {
				row_chk[i][k] = true;
				col_chk[j][k] = true;
				part_chk[(i / 3) * 3 + (j / 3)][k] = true;
				board[i][j] = k+1;
				recursion(curr + 1);
				row_chk[i][k] = false;
				col_chk[j][k] = false;
				part_chk[(i / 3) * 3 + (j / 3)][k] = false;
				board[i][j] = 0;
			}

		}
	}
	
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	int tmp; 
	vector<int> ans;

	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		
		for (int j = 8; j >= 0; j--) {
			
			board[i][j] = tmp%10;
			tmp = tmp/10;
			if (board[i][j] != 0) {
				row_chk[i][board[i][j]-1] = true;
				col_chk[j][board[i][j]-1] = true;
				part_chk[(i / 3) * 3 + (j / 3)][board[i][j]-1] = true;
			}
		}
	}
	
	recursion(0);
	ans = v;


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << ans[i * 9 + j];
		}
		cout << '\n';
	}

	return 0;
}
