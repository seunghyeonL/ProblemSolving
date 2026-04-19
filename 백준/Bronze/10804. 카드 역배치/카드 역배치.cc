#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	int arr[20];
	for (int i = 0; i < 20; i++) {
		arr[i] = i+1;
	}
	int tmp[20];
	int A, B;
	for(int n=0;n<10;n++) {
		cin >> A >> B;

		for (int i=0; i<=B-A; i++) {
			tmp[A+i-1] = arr[B-i-1];
		}
		for (int i=A; i<=B; i++) {
			arr[i-1] = tmp[i-1];
		}

	}
	for (int i = 0; i < 20; i++) {
		cout << arr[i]<< ' ';
	}
	 
	return 0;
}