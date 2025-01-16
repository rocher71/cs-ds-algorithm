/*
 * ������ ������ ������ ���ٴ� ������ ���� ������, 
 * bool visit �迭�� �ƴ� time���� �̹� �湮�ߴ� �����̴���
 * �Ŀ� �� ª�� ��ΰ� �ִٸ� �����ؾ���
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

		// �ι�, �ѹ��� �ؾ��Ѵٴ� ���� x ��� �ι�� ������
		int next = curr * 2;
		if (next <= 200000 && time[next] > currTime) {
			q.push({ next, currTime });
			time[next] = currTime;
		}
		// �ڷ� ��ĭ
		next = curr - 1;
		if (next >= 0 && time[next] > currTime + 1) {
			q.push({ next, currTime + 1 });
			time[next] = currTime + 1;
		}
		// ������ ��ĭ
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