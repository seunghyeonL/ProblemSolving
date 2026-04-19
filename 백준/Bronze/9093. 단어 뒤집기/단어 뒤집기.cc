#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimeter);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	string line;
	
	cin >> T;

	cin.ignore();
	for (int i = 0; i < T; i++) {
		getline(cin, line);
		vector<string> v = split(line, ' ');
		
		for (int j = 0; j < v.size(); j++) {
			reverse(v[j].begin(), v[j].end());
			cout << v[j] << ' ';
		}
        if(i==T-1) break;
		cout << '\n';
	}
	
	   	  
	return 0;
}

vector<string> split(string str, char delimeter) {
	vector<string> ans;
	stringstream ss(str);
	string tmp;

	while (getline(ss, tmp, delimeter)) {
		ans.push_back(tmp);
	}

	return ans;
}