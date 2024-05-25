#include<iostream>
using namespace std;

int T;
int getGcd(int x, int y) {
	if (y == 0) return x;
	return getGcd(y, x % y);
}

int main() {
	cin >> T;

	while (T--) {
		int west;
		int east;

		cin >> west >> east;

		int numerator = 1;
		int denomenator = 1;

		for (int i = 0; i < west; i++) {
			numerator *= (east - i);
			denomenator *= (west - i);
			int gcd = getGcd(numerator, denomenator);
			numerator /= gcd;
			denomenator /= gcd;
		}
		int count = numerator / denomenator;
		cout << count <<"\n";
	}
	

}