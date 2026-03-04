#include<iostream>
#include<deque>
#include<algorithm>
#include<queue>
#include<array>
#include<vector>
#define DELETED -1
using namespace std;

int n, m, t;
vector<array<int, 3>> cmds;
deque<double> wheels[51];
int visit[51][51];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void calcWithAvg(double avg){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m ;j++){
            if(wheels[i][j] == DELETED) continue;
            if(wheels[i][j] > avg) wheels[i][j]--;
            else if(wheels[i][j] < avg) wheels[i][j]++;
        }
    }
}

double getAvg(){
    double sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(wheels[i][j] == DELETED) continue;
            sum += wheels[i][j];
            cnt++;
        }
    }
    return sum / cnt;
}

// 인접한 수 확인 후 같은 수 없애고 그런 수가 없다면 false return
int bfs(int y, int x, int turn){
    queue<pair<int, int>> q;
    visit[y][x] = turn;
    q.push({y, x});
    int num = wheels[y][x], cnt = 0;

    while(!q.empty()){
        int currWheel = q.front().first;
        int currIdx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextWheel = currWheel + dy[i];
            int nextIdx = (currIdx + dx[i]) % m; // idx 넘어 가면 원판 첫번째 원소로 변경

            if(nextIdx == -1) nextIdx = m - 1; // 원판 마지막 원소로 변경
            if(nextWheel <= 0 || nextWheel > n) continue;
            if(wheels[nextWheel][nextIdx] != num) continue;

            // 같은 원소 발견
            cnt++;
            visit[nextWheel][nextIdx] = turn;
            q.push({nextWheel, nextIdx});
            wheels[nextWheel][nextIdx] = DELETED;
        }
    }
    return cnt;
}

void rotate(int wheelNum, int d, int cnt){
    for(int i = 0; i < cnt; i++){
        // 시계
        if(d == 0){
            int last = wheels[wheelNum].back();
            wheels[wheelNum].pop_back();
            wheels[wheelNum].push_front(last);
            continue;
        }
        // 반시계
        int first = wheels[wheelNum].front();
        wheels[wheelNum].pop_front();
        wheels[wheelNum].push_back(first);
    }
}

void print(string str){
    return;
    cout << "\nAfter " << str << "\n";
    for(int i = 1 ; i <= n ;i++){
        for(int j = 0; j < m; j++){
            if(wheels[i][j] == DELETED) cout << "- ";
            else cout << wheels[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            wheels[i].push_back(a);
        }
    }

    for(int i = 0; i < t; i++){
        int x, d, k;
        cin >> x >> d >> k;
        cmds.push_back({x, d, k});
    }

    for(int turn = 0; turn < t; turn++){
        int x = cmds[turn][0];
        int d = cmds[turn][1];
        int k = cmds[turn][2];

        // xi의 배수인 원판들 모두 회전
        for(int i = x; i <= n; i += x){
            rotate(i, d, k);
            print(to_string(i) + " 회전");
        }

        int deletedCnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m; j++){
                if(visit[i][j] == turn + 1 || wheels[i][j] == DELETED) continue;
                deletedCnt += bfs(i, j, turn + 1);
            }
        }
        print("bfs");

        // 인접한 같은 수가 있는 경우 continue
        if(deletedCnt != 0) continue;

        // 없는 경우 평균 구하기
        double avg = getAvg();

        // 평균에 따라 값 변경
        calcWithAvg(avg);
        print("평균 처리");
    }


    int sum = 0;
    for(int i = 1 ; i <= n ;i++){
        for(int j = 0; j < m; j++){
            if(wheels[i][j] == DELETED) continue;
            sum += wheels[i][j];
        }
    }

    cout << sum << "\n";
    return 0;
}