#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
//#include <fstream>

using namespace std;

int N;
vector<int> road;
vector<int> city;
long long int pay;


int detect(int curr) {
	int tmp=curr;
	int cnt=1;
	while (tmp+cnt<N-1) {
		if (city[tmp + cnt] < city[curr]) break;
		cnt++;
	}
	return cnt;
}


void move(int curr) {
	if (curr == N - 1) return;
	int mov_dis;
	long long int buy_fuel = 0;
	mov_dis = detect(curr);

	for (int i = 0; i < mov_dis; i++) {
		buy_fuel += road[curr + i];
	}
	pay += city[curr] * buy_fuel;
	move(curr + mov_dis);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

//	ifstream input("input.txt");
//	input >> N;
    cin >> N;
    
	int tmp;

	for (int i = 0; i < N - 1; i++) {
		//input >> tmp;
        cin >> tmp;
		road.push_back(tmp);
	}
	
	for (int i = 0; i < N; i++) {
		//input >> tmp;
        cin >> tmp;
		city.push_back(tmp);
	}
	
	move(0);
	
	cout << pay;

	return 0;
}
