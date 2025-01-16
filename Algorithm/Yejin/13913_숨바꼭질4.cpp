#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int from, to, last;
int time[200001], previous[200000];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, from });
	time[from] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int currCost = pq.top().first;
		pq.pop();

		if (curr == to) return;

		int next = curr * 2;
		if (next <= 200000 && currCost + 1 < time[next]) {
			time[next] = currCost + 1;
			pq.push({ time[next], next });
			previous[next] = curr;
		}

		next = curr + 1;
		if (next <= 200000 && currCost + 1 < time[next]) {
			time[next] = currCost + 1;
			pq.push({ time[next], next });
			previous[next] = curr;
		}

		next = curr - 1;
		if (next >= 0 && currCost + 1 < time[next]) {
			time[next] = currCost + 1;
			pq.push({ time[next], next });
			previous[next] = curr;
		}
	}
}

int main() {
	cin >> from >> to;
	fill_n(time, 200000, INT_MAX);

	dijkstra();

	cout << time[to] << "\n";


	vector<int> route;
	route.push_back(to);

	int idx = to;
	while (idx != from) {
		route.push_back(previous[idx]);
		idx = previous[idx];
	}

	for (int i = route.size() - 1; i >= 0; i--) cout << route[i] << " ";
	cout << "\n";
}