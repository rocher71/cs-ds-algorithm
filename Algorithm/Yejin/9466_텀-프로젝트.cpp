#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc, n, teamStudentCnt;
int arr[100001]; // arr[a] = b : a가 b지목
bool self[100001]; //self[a] = true -> a는 셀프지목 한 학생, false 면 셀프지목 x
int visit[100001];
vector<int> indeg[100001]; //indeg[a] = {a, b, c, d} : a를 지목한 학생들은 a, b, c, d

int bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = start;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		int nxt = arr[curr];
		
		// 싸이클 발견
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

		// 초기화
		teamStudentCnt = 0;
		fill_n(arr, n + 1, 0);
		fill_n(self, n + 1, false);
		fill_n(visit, n + 1, 0);
		for (int i = 0; i <= n; i++) indeg[i].clear();

		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			
			
			// 셀프지목한 학생에 대한 처리
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
		//스스로 뽑은 학생 처리 
		1. 셀프지목한 학생
		2. 1을 지목한 학생
		예를들어 1->3, 2->1, 3->3, 4->3 이라면 이들은 싸이클을 형성할 수 없다(고 생각했음..)
		1, 3, 4에 대해서 bfs를 아예 돌지 않도록 arr배열을 -1로 갱신
		
		셀프 지목 관련 코드를 지우지 않으면
		예제, 게시판의 반례, 스스로 생각한 반례 모두 정답이 출력되나 제출시 15%에서 틀렸다고 나옴
		지우면 정답 처리됨
		*/
		
		for (int i = 1; i <= n; i++) {
			if (!self[i]) continue;

			for (int j = 0; j < indeg[i].size(); j++) {
				arr[indeg[i][j]] = -1;
			}
		}
		

		// 셀프지목으로 -1된 정점들 + 방문한 정점들 을 제외하고 bfs() 실행
		for (int i = 1; i <= n; i++) {
			if (arr[i] == -1 || visit[i]) continue;
			teamStudentCnt += bfs(i);
		}

		cout << n - teamStudentCnt << "\n";

	}
}