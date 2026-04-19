#include <iostream>
#include <string>
#include <vector>

using namespace std;

int stk[10005];
int* Top;


void push(int n) {
	Top += 1;
	*Top = n;
}

void pop(void) {
	if (Top == stk) cout << -1 << '\n';
	else {
		cout << *Top << '\n';
		Top -= 1;
	}
}

void size(void) {
	cout << Top - stk << '\n';
}

void empty(void) {
	if (Top == stk) cout << 1 << '\n';
	else cout << 0 << '\n';
}

void top(void) {
	if (Top == stk) cout << -1 << '\n';
	else cout << *Top << '\n';
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	string inst;
	int x;
	Top = stk;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> inst;
		if (inst == "push") cin >> x;
		
		if (inst == "pop")
			pop();
		else if (inst == "size")
			size();
		else if (inst == "empty")
			empty();
		else if (inst == "top")
			top();
		else 
			push(x);
				
	}

	return 0;
}