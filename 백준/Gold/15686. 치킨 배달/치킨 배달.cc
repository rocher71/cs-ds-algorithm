#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pii;
int n, m, houseCnt;
int arr[51][51], dist[14][51][51];
bool visit[51][51];
//vector<pair<int, pair<int, int>>> chickenDist; // cd[a] = b : a 치킨집만 있을 때의 치킨거리

// {{y좌표, x좌표}, {해당 치킨집이 제일 가까운 집들의 개수, 모든 집에서 해당치킨집까지 거리의 합}}
map<pair<int, int>, pair<int, int>> leastCntMap;
vector<pii> chickens;
vector<pii> houses;
vector<int> perm;

// {{해당 치킨집이 제일 가까운 집들의 개수, 모든 집에서 해당치킨집까지 거리의 합}, {y, x}}
vector<pair<pair<int, int>, pair<int, int>>> nearestChicken;
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

bool compare1(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.first != b.first.first) return a.first.first > b.first.first;
	return a.first.second < b.first.second;
}

/*
int bfsFromChicken(int fromY, int fromX) {
	int currHouse = 0, chickenCnt = 0;
	fill(&dist[0][0], &dist[n - 1][n], 0);
	queue<pair<int, int>> q;
	q.push({ fromY, fromX });

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();

		if (arr[currY][currX] == 1) {
			currHouse++;
			chickenCnt += dist[currY][currY];
		}
		if (currHouse == houseCnt) return chickenCnt;

		for (int i = 0; i < 4; i ++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (dist[nextY][nextX]) continue;

			dist[nextY][nextX] = dist[currY][currX] + 1;
			q.push({ nextY, nextX });
		}
	}
	return 0;
}*/
/*
int bfsFromHouse(int y, int x, bool check) {
	queue<pair<int, int>> q;
	fill(&dist[0][0], &dist[n - 1][n], 0);
	q.push({ y, x });
	bool isFirst = true;
	//cout << "-------------- 집 좌표 : (" << y << ", " << x << ")-----------------------" << "\n";

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;

		q.pop();

		if (arr[currY][currX] == 2) {
			if (!check) return dist[currY][currX];
			//cout << "찾은 치킨집 좌표 : (" << currY << ", " << currX << ")\n";
			//cout << "집부터 여기까지 거리 : " << dist[currY][currX];

			if (leastCntMap.find({ currY, currX }) == leastCntMap.end()) {
				leastCntMap.insert({ {currY, currX}, {isFirst ? 1 : 0, dist[currY][currX] } });
				if (isFirst == true) isFirst = false;
			}
			else {
				leastCntMap[{currY, currX}] = make_pair(leastCntMap[{currY, currX}].first + (isFirst ? 1 : 0), dist[currY][currX] + leastCntMap[{currY, currX}].second);
				if (isFirst == true) isFirst = false;
			}
			//cout << ", map[curry, currx] 값 : " << leastCntMap[{currY, currX}].first << " , " << leastCntMap[{currY, currX}].second << "\n";
		}

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (dist[nextY][nextX] != 0) continue;

			q.push({ nextY, nextX });
			dist[nextY][nextX] = dist[currY][currX] + 1;
		}
	}
	return 0;
}*/

// y, x 치킨집으로부터 모든 집까지의 거리를 기록
void bfsFromChicken(int idx, int y, int x) {
	fill(&visit[0][0], &visit[n - 1][n], false);
	queue<pii> q;
	q.push({ y, x });
	dist[idx][y][x] = 0;
	int houseCnt = 0;

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();

		if (arr[currY][currX] == 1) houseCnt++;
		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (visit[nextY][nextX]) continue;

			q.push({ nextY, nextX });
			dist[idx][nextY][nextX] = dist[idx][currY][currX] + 1;
			visit[nextY][nextX] = true;

			if (arr[nextY][nextX] == 1) {
				houseCnt++;
				//cout << "치킨집 " << idx << " 에서 " << nextY << ", " << nextX << " 거리 : " << dist[idx][nextY][nextX] << "\n";
			}
			//if (houseCnt == houses.size()) return;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) houses.push_back({ i, j });
			if (arr[i][j] == 2) houseCnt++;
			if (arr[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	for (int i = 0; i < chickens.size() - m; i++) perm.push_back(0);
	for (int i = 0; i < m; i++) perm.push_back(1);



	for (int i = 0; i < chickens.size(); i++) bfsFromChicken(i, chickens[i].first, chickens[i].second);

	int minCityDist = 3000;
	do {// 0 1 1 0
		int cityDist = 0;
		//cout << "============================================================\n이번 조합 : ";
		//for (int j = 0; j < perm.size(); j++) {
		//	cout << perm[j] << " ";
		//}
		//cout << "\n";

		for (int i = 0; i < houses.size(); i++) {
			int houseY = houses[i].first;
			int houseX = houses[i].second;
			int currDist = 3000;
		//	cout << "집 위치 : " << houseY << ", " << houseX << "\n";
			for (int j = 0; j < perm.size(); j++) {
				if (perm[j] == 0) continue;
				currDist = min(currDist, dist[j][houseY][houseX]);
				
			}
			cityDist += currDist;
			
		//	cout << "현재 집의 치킨 거리 : " << currDist << "\n현재까지 도시의 치킨 거리 : " << cityDist << "\n";
		}
		minCityDist = min(minCityDist, cityDist);
	} while (next_permutation(perm.begin(), perm.end()));


	int ans = 0;
	cout << minCityDist << "\n";


	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 1) continue;

			// 치킨집, 이 치킨집만 있을 때 치킨거리
			//bfsFromChicken(i, j);
			//chickenDist.push_back({ dist, {i, j} });

			//최소거리 치킨집
			bfsFromHouse(i, j, true);
		}
	}

	for (pair<pii, pii> pii : leastCntMap) {
		nearestChicken.push_back({ {pii.second.first, pii.second.second}, { pii.first.first, pii.first.second } });
	}

	sort(nearestChicken.begin(), nearestChicken.end(), compare1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 2) continue;
			arr[i][j] = 0;
		}
	}

	//cout << "nearestChicken.size()-1 : " << nearestChicken.size() - 1 << "\nnearestChicken.size() <= m" << (nearestChicken.size() <= m) << "\n";
	// 남은 치킨집들만 배정
	int forCnt = nearestChicken.size() < m ? nearestChicken.size() : m;
	for (int i = 0; i < forCnt; i++) {
		arr[nearestChicken[i].second.first][nearestChicken[i].second.second] = 2;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 1) continue;
			// 각 집별로 최단거리 치킨집까지
			ans += bfsFromHouse(i, j, false);
		}
	}*/

	return 0;
}

/*
반례
5 1
2 0 1 0 2
0 0 0 0 0
1 0 2 0 1
0 0 0 0 0
2 0 1 0 2
*/