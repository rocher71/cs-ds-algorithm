#include<iostream>
#include<string>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

bool hasTwoContinuous(string str) {
	char prev = str[0];
	string contStr = "";
	for (int i = 1; i < str.length(); i++) {
		char curr = str[i];
		if (prev != curr) {
			prev = curr;
			continue;
		}
		if(curr != 'e' && curr != 'o') return true;
	}
	return false;
}

bool hasThreeContinuous(string str) {
	bool isPrevVowel = isVowel(str[0]);
	int cnt = 0;
	for (int i = 1; i < str.length(); i++) {
		bool isCurrVowel = isVowel(str[i]);
		if (isPrevVowel != isCurrVowel) {
			cnt = 0;
			isPrevVowel = isCurrVowel;
			continue;
		}

		cnt++;
		if (cnt < 2) continue;
		return true;
	}
	return false;
}

bool hasVowel(string str) {
	if (str.find('a') != string::npos) return true;
	if (str.find('e') != string::npos) return true;
	if (str.find('i') != string::npos) return true;
	if (str.find('o') != string::npos) return true;
	if (str.find('u') != string::npos) return true;
	return false;
}

void printNotAcceptable(string str) {
	cout << '<' << str << '>' << " is not acceptable.\n";
	return;
}

void printAcceptable(string str) {
	cout << '<' << str << '>' << " is acceptable.\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	while (str != "end") {
		if (!hasVowel(str)) {
			printNotAcceptable(str);
			cin >> str;
			continue;
		}
		
		if (hasThreeContinuous(str)) {
			printNotAcceptable(str);
			cin >> str;
			continue;
		}

		if (hasTwoContinuous(str)) {
			printNotAcceptable(str);
			cin >> str;
			continue;
		}

		printAcceptable(str);
		cin >> str;


	}

}