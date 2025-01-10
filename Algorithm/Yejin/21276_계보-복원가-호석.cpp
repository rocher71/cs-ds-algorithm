#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v[1001];
vector<int> directKids[1001];
vector<string> roots, names;
unordered_map<string, int> nameToIdx;
string idxToName[1001];
int deg[1001];

void topology() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			deg[next]--;
			
			// next�� indegree�� 0���� ����� ��(curr)�� next�� ����θ�
			if (deg[next] == 0) {
				q.push(next);
				directKids[curr].push_back(next);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		names.push_back(str);
		nameToIdx.insert({ str, i });
		idxToName[i] = str;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;

		int x = nameToIdx.find(a)->second;
		int y = nameToIdx.find(b)->second;

		// x y�� x�� ���� �� y�� �ִٴ� �ǹ�������, 
		// ���� y -> �ڽ� x ���·� �׷��� v�� �������
		v[y].push_back(x);
		deg[x]++;
	}
	

	// deg�� 0�� ������� ����
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) roots.push_back(idxToName[i]);
	}

	topology();

	int rootCnt = 0;


	sort(roots.begin(), roots.end());
	sort(names.begin(), names.end());

	cout << roots.size() << "\n";
	for (string name : roots) cout << name << " ";
	cout << "\n";

	for (int i = 0; i < n; i++) {
		string curr = names[i];
		int currIdx = nameToIdx[curr];
		cout << curr << " " << directKids[currIdx].size() << " ";
		if (directKids[currIdx].size() == 0) {
			cout << "\n";
			continue;
		}

		// �̸��� ������ ���� string vector 'kids'
		vector<string> kids;
		for (int kid : directKids[currIdx])	kids.push_back(idxToName[kid]);
		sort(kids.begin(), kids.end());

		for (string kid : kids) cout << kid << " ";
		cout << "\n";
	}

	return 0;
}