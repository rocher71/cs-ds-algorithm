#include<iostream>
#include<set>
using namespace std;

int n;
set<int> s;
set<int>::iterator it;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}

}