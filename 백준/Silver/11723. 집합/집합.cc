#include<iostream>
#include<algorithm>
using namespace std;

bool isIn[21];
int m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m;
	string cmd;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd != "all" && cmd != "empty") cin >> num;

		if (cmd == "add") {
			if (!isIn[num]) isIn[num] = true;
		}
		else if (cmd == "remove") {
			if (isIn[num]) isIn[num] = false;
		}
		else if (cmd == "check") {
			if (isIn[num]) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "toggle") {
			if (isIn[num]) isIn[num] = false;
			else isIn[num] = true;
		}
		else if (cmd == "all") {
			for (int j = 1; j <= 20; j++) isIn[j] = true;
		}
		else if (cmd == "empty") {
			for (int j = 1; j <= 20; j++) isIn[j] = false;
		}
	}
}