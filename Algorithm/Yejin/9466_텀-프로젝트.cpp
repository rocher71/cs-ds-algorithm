#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc, n, teamStudentCnt;
int arr[100001]; // arr[a] = b : a�� b����
bool self[100001]; //self[a] = true -> a�� �������� �� �л�, false �� �������� x
int visit[100001];
vector<int> indeg[100001]; //indeg[a] = {a, b, c, d} : a�� ������ �л����� a, b, c, d

int bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = start;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		int nxt = arr[curr];
		
		// ����Ŭ �߰�
		if (visit[nxt] == start) {
			int cnt = 1, cycleIdx = arr[nxt];

			while (cycleIdx != nxt) {
				cycleIdx = arr[cycleIdx];
				cnt++;
			}
			return cnt;

		}

		if (arr[nxt] == -1 || visit[nxt]) continue;
		visit[nxt] = start;
		q.push(nxt);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> tc;
	while (tc--) {
		cin >> n;

		// �ʱ�ȭ
		teamStudentCnt = 0;
		fill_n(arr, n + 1, 0);
		fill_n(self, n + 1, false);
		fill_n(visit, n + 1, 0);
		for (int i = 0; i <= n; i++) indeg[i].clear();

		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			
			
			// ���������� �л��� ���� ó��
			if (i == tmp) {
				self[i] = true;
				arr[i] = -1;
				teamStudentCnt++;
				continue;
			}
			indeg[tmp].push_back(i);
			
			arr[i] = tmp;
		}

		/*
		//������ ���� �л� ó�� 
		1. ���������� �л�
		2. 1�� ������ �л�
		������� 1->3, 2->1, 3->3, 4->3 �̶�� �̵��� ����Ŭ�� ������ �� ����(�� ��������..)
		1, 3, 4�� ���ؼ� bfs�� �ƿ� ���� �ʵ��� arr�迭�� -1�� ����
		
		���� ���� ���� �ڵ带 ������ ������
		����, �Խ����� �ݷ�, ������ ������ �ݷ� ��� ������ ��µǳ� ����� 15%���� Ʋ�ȴٰ� ����
		����� ���� ó����
		*/
		
		for (int i = 1; i <= n; i++) {
			if (!self[i]) continue;

			for (int j = 0; j < indeg[i].size(); j++) {
				arr[indeg[i][j]] = -1;
			}
		}
		

		// ������������ -1�� ������ + �湮�� ������ �� �����ϰ� bfs() ����
		for (int i = 1; i <= n; i++) {
			if (arr[i] == -1 || visit[i]) continue;
			teamStudentCnt += bfs(i);
		}

		cout << n - teamStudentCnt << "\n";

	}
}