#include<iostream>
#include<queue>
#define MAX 32001
using namespace std;

int n, m;
int deg[MAX];
vector<int> pre[MAX];

void topology() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();

		cout << curr << " ";

		if (pre[curr].size() == 0) continue;
		
		for (int i = 0; i < pre[curr].size(); i++) {
			int next = pre[curr][i];
			if (--deg[next] == 0) pq.push(next);
		}

		//deg[pre[curr]]--;
		//if (deg[pre[curr]] == 0) pq.push(pre[curr]);
	}
	
}

int main() {
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pre[a].push_back(b);
		deg[b]++;
	}

	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}

	topology();

	
}