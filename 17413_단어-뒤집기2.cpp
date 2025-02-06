#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

string s;
vector<char> ans;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	getline(cin, s);

	//cout << s << "\n";
	bool isTag = false;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		char curr = s[i];

		if (!isTag && ((curr >= 'a' && curr <= 'z') || (curr >= '0' && curr <= '9'))) {
			st.push(curr);
			continue;
		}

		// 문자열 끝난 상황
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}

		ans.push_back(curr);

		if (curr == '<') isTag = true;
		else if (curr == '>') isTag = false;

		// ' '
		// continue
	}

	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	for (char c : ans) cout << c;
	cout << "\n";
}