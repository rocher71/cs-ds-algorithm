#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
using namespace std;

int n, p, newScore, ans = -1;
vector<int> score, cnt, place;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> newScore >> p;

	if (n == 0) {
		cout << "1\n";
		return 0;
	}

	int tmp;
	cin >> tmp;
	score.push_back(tmp);
	cnt.push_back(1);
	place.push_back(1);
	
	if (newScore >= tmp) ans = 1;


	for (int i = 1; i < n; i++) {
		cin >> tmp;
		if (/*i != n -1 &&*/ tmp == score[score.size() - 1]) {
			cnt[cnt.size() - 1]++;
			continue;
		}
		if (ans != -1) continue;

		/* 답에 딱히 문제가 되지 않아서 굳이 처리안해줘도됨
		if (i == n - 1 && tmp == score[score.size() - 1]) {
			cnt[cnt.size() - 1]++;8 10 10
		}*/

		score.push_back(tmp);
		int nextPlace = place[place.size() - 1] + cnt[cnt.size() - 1];
		place.push_back(nextPlace);
		cnt.push_back(1);

		if (newScore >= tmp) {
			ans = nextPlace;
		}
	}

	if (n == p && newScore <= tmp) cout << "-1\n";
	else if (ans == -1) cout << place[place.size() - 1] + cnt[cnt.size() - 1] << "\n";
	else 	cout << ans << "\n";

	return 0;
}

/*
8 10 10
100 90 90 90 80 60 60 50
답 : 9

5 5 6
10 10 10 5 5
4

5 4 6
10 10 10 5 5
6

5 4 6
2 2 2 2 2
1

4 50 5
40 40 40 40
1

4 50 5
40 30 30 20
1

4 50 5
50 40 40 40
1

4 50 5
50 50 50 50
1

4 50 5
60 40 40 40 
2

4 50 5
60 59 40 40
3

4 50 5
60 50 50 40
2

4 50 5
60 50 50 50
2

4 50 5
60 50 30 20
2

4 50 5
60 59 58 57
5

4 50 5
60 50 50 50
2

5 5 5
7 6 5 5 4
3

5 5 5
7 6 5 5 4
3

5 5 5
7 7 5 5 4
3

5 5 5
7 5 5 5 4
2

5 5 5 
10 9 8 7 6
-1

*/