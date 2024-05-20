#include<iostream>
#include<set>
using namespace std;

int n;
set<pair<int, string>> s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert({ str.length(), str });
	}

	for (set<pair<int, string>>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << it->second << "\n";
	}
	return 0;
}