#include<iostream>	
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;
string s;

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, s.length() - i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < s.length(); i++) {
		cout << v[i] << "\n";
	}
}