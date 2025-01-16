/*
 * 무조건 최적의 순서로 간다는 보장이 없기 때문에, 
 * bool visit 배열이 아닌 time으로 이미 방문했던 지점이더라도
 * 후에 더 짧은 경로가 있다면 갱신해야함
 */
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int from, to;
int time[200001];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ from, 0 });
	q.push({ from * 2, 0 });
	time[from] = 0;
	time[from * 2] = 0;

	while (!q.empty()) {
		int curr = q.front().first;
		int currTime = q.front().second;
		q.pop();

		if (curr == to) return;

		// 두배, 한번만 해야한다는 조건 x 계속 두배로 가도됨
		int next = curr * 2;
		if (next <= 200000 && time[next] > currTime) {
			q.push({ next, currTime });
			time[next] = currTime;
		}
		// 뒤로 한칸
		next = curr - 1;
		if (next >= 0 && time[next] > currTime + 1) {
			q.push({ next, currTime + 1 });
			time[next] = currTime + 1;
		}
		// 앞으로 한칸
		next = curr + 1;
		if (next <= 200000 && time[next] > currTime + 1) {
			q.push({ next, currTime + 1 });
			time[next] = currTime + 1;
		}


	}
}

int main() {
	cin >> from >> to;
	fill_n(time, 200000, 1e9);

	bfs();

	cout << time[to] << "\n";
}