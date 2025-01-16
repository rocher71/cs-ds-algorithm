#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int from, to;
int time[200001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, from });
	time[from] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int currTime = pq.top().first;
		pq.pop();

		if (curr == to) return;

		int next = curr * 2;
		if (next <= 200000 && currTime< time[next]) {
			pq.push({ currTime, next });
			time[next] = currTime;
		}

		next = curr + 1;
		if (next <= 200000 && currTime + 1 < time[next]) {
			pq.push({ currTime + 1, next });
			time[next] = currTime + 1;

		}

		next = curr - 1;
		if (next <= 200000 && currTime + 1 < time[next]) {
			pq.push({ currTime + 1, next });
			time[next] = currTime + 1;
		}
	}
}

int main() {
	cin >> from >> to;
	fill_n(time,200000, INT_MAX);

	dijkstra();

	cout << time[to] << "\n";

	return 0;
}