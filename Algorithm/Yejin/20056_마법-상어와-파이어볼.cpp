// 삼성 코테
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, totalMass;
//int fireball[2501][5]; //row, col, 질량, 속력, 방향
// 위, 오른쪽 위, 오른쪽, 오른쪽 아래, 아래, 왼쪽 아래, 왼쪽, 왼쪽 위
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<pair<int, int>, pair<int, int>>> graph[51][51]; // graph[y][x] = {{횟수, 질량}, {속력, 방향}}

void separate(int currY, int currX, int idx){
    int massSum = 0, speedSum = 0, evenCnt = 0, oddCnt = 0, ballCnt = 0;

//    for(auto it = graph[currY][currX].begin(); it != graph[currY][currX].end(); it++){
//        if(it->first.first != idx) continue;
//        ballCnt++;
//        massSum += it->first.second;
//        speedSum += it->second.first;
//        if(it->second.second % 2 == 0) evenCnt++;
//        else oddCnt++;
//        it->first.first--;
//    }
    for(auto currBall : graph[currY][currX]){
        if(currBall.first.first != idx) continue;
        ballCnt++;
        massSum += currBall.first.second;
        speedSum += currBall.second.first;
        if(currBall.second.second % 2 == 0) evenCnt++;
        else oddCnt++;
    }

    if(ballCnt <2) return;

    for(auto it = graph[currY][currX].begin(); it != graph[currY][currX].end(); it++){
        if(it->first.first != idx) continue;
        it->first.first--;
    }

    int newMass = massSum/5, newSpeed = speedSum/ballCnt;
    bool isAllEvenOrOdd = evenCnt == ballCnt || oddCnt == ballCnt ? true : false;

//    graph[currY][currX].clear();

    totalMass -= massSum; //전체 질량 합에서 현 위치에 있던 파이어볼 질량 빼줌
    if(newMass == 0) return; // 질량이 0인 파이어볼은 소멸
    totalMass += newMass * 4; // 전체 질량에 새로운 질량*4개 더해줌

   for(int i = 0; i<4; i++){
        // 모두 짝/홀이면 0,2,4,6 그렇지 않으면 1,3,5,7
        int newDirection = isAllEvenOrOdd ? 2 * i : 2*i + 1;
        graph[currY][currX].push_back({{idx, newMass}, {newSpeed, newDirection}});
   }
}

void solve(int currY, int currX, int idx){
    map<pair<int, int>, int> count;
    for(int i = 0; i<graph[currY][currX].size(); i++){
        pair<pair<int, int>, pair<int, int>> currBall = graph[currY][currX][i];

        // 직전 회차에 위치한 공이 아니면 continue (이번 회차에 이동된 파이어볼과 구분)
        if(currBall.first.first != idx-1) continue;
        int nxtY = (currY + dy[currBall.second.second] * currBall.second.first) % n;
        int nxtX = (currX + dx[currBall.second.second] * currBall.second.first) % n;
        nxtY = nxtY < 0 ? nxtY + n : nxtY;
        nxtX = nxtX < 0 ? nxtX + n : nxtX;

        // 이전 좌표에 있던 파이어볼 지우기
//        graph[currY][currX].erase(find(graph[currY][currX].begin(), graph[currY][currX].end(), currBall));

        // 새로운 좌표에 위치시키기
        currBall.first.first = idx;
        graph[nxtY][nxtX].push_back(currBall);

        // 좌표별 개수 갱신
        if(count.find({nxtY, nxtX}) != count.end()) count[{nxtY, nxtX}] = 1;
        else count[{nxtY, nxtX}]++;
    }

    // 새로 위치된 좌표들 중 두개 이상 있는 곳은 분리 -> 이걸 중간에 하면 안되고, 한 싸이클을 다 돈 뒤에 해야함..
//    for(auto it = count.begin(); it != count.end(); it++){
//        if(it->second + graph[it->first.first][it->first.second].size() == 2) continue;
//        separate(it->first.first, it->first.second, idx);
//    }

    /*
    for(int i = 0; i<graph[currY][currX].size(); i++){
        const Fireball currBall = graph[currY][currX][i];
        int nxtY = (currY + dy[currBall.direction] * currBall.speed) % n;
        int nxtX = (currX + dx[currBall.direction] * currBall.speed) % n;
        nxtY = nxtY < 0 ? nxtY + n : nxtY;
        nxtX = nxtX < 0 ? nxtX + n : nxtX;

        // 새로운 좌표에 위치시키기
        graph[nxtY][nxtX].push_back(currBall);
        graph[currY][currX].erase(find(graph[currY][currX].begin(), graph[currY][currX].end(), currBall));
    } */

    /*
    map<pair<int, int>, int> count;
    for(int i = 0; i<fireballs.; i++){
        int currY = fireball[i][0];
        int currX = fireball[i][1];
        int nxtY = (currY + dy[fireball[i][4]] * fireball[i][3]) % n;
        int nxtX = (currX + dx[fireball[i][4]] * fireball[i][3]) % n;
        nxtY = nxtY < 0 ? nxtY + n : nxtY;
        nxtX = nxtX < 0 ? nxtX + n : nxtX;

        graph[nxtY][nxtX].push_back(i);
        graph[currY][currX].erase(find(graph[currY][currX].begin(), graph[currY][currX].end(), i));
        //if(find(graph[currY][currX].begin(), graph[currY][currX].end(), i) != graph[currY][currX].end())
        if(count.find({nxtY, nxtX}) != count.end()) count[{nxtY, nxtX}] = 1;
        else count[{nxtY, nxtX}]++;
    }

    for(map<pair<int, int>, int>::iterator it = count.begin(); it != count.end(); it++){
        if(it->second == 1) continue;
        separate(it->first.first, it->first.second);
    }
     */
}

int main(){

    cin >> n >> m >> k;
    for(int i = 0; i<m; i++){
        int r, c, mass, d, s;
        cin >> r >> c >> mass >> s >> d;
        totalMass += mass;
        // 파이어볼의 초기 좌표에 위치시키기
        graph[--r][--c].push_back({{0, mass}, {s, d}});
    }

    //k번 이동
    for(int i = 1 ; i <= k; i++){
        for(int j = 0; j<n; j++){
            for(int l = 0; l < n ; l++){
                if(graph[j][l].empty()) continue;
                solve(j, l, i);
            }
        }
        for(int j = 0; j< n; j++){
            for(int l = 0; l < n; l++){
                if(graph[j][l].size() < 2) continue;
                separate(j, l, i);
            }
        }
//        cout<< i <<"회 진행 완료\n";
    }

    cout << totalMass <<"\n";


}

/*
다 똑같고 주석만 정리했는데 아래 코드는 시간 초과 나옴..

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, totalMass;
// 위, 오른쪽 위, 오른쪽, 오른쪽 아래, 아래, 왼쪽 아래, 왼쪽, 왼쪽 위
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<pair<int, int>, pair<int, int>>> graph[51][51]; // graph[y][x] = {{회차, 질량}, {속력, 방향}}

// 같은 칸에 같은 회차의 파이어볼이 두개 이상 있을 시 분리시키는 함수
void separate(int currY, int currX, int idx){
// 칸에 파이어볼이 2개 이상 있더라도, 이번 회차에서 옮겨진 볼이 아닐 수 있기 때문에 ballCnt로 구분
int massSum = 0, speedSum = 0, evenCnt = 0, oddCnt = 0, ballCnt = 0;

for(auto currBall : graph[currY][currX]){
if(currBall.first.first != idx) continue;
ballCnt++;
massSum += currBall.first.second;
speedSum += currBall.second.first;
if(currBall.second.second % 2 == 0) evenCnt++;
else oddCnt++;
}

// 이번 회차의 볼이 2개 이상이 아닐 경우 return
if(ballCnt <2) return;

// 회차 구분을 위해 사라진 파이어볼들은 회차값 차감
for(auto it = graph[currY][currX].begin(); it != graph[currY][currX].end(); it++){
if(it->first.first != idx) continue;
it->first.first--;
}

int newMass = massSum/5, newSpeed = speedSum/ballCnt;
bool isAllEvenOrOdd = evenCnt == ballCnt || oddCnt == ballCnt ? true : false;

// 전체 질량합 갱신
totalMass -= massSum; //전체 질량 합에서 현 위치에 있던 파이어볼 질량 빼줌
if(newMass == 0) return; // 새로 생긴 파이어볼들의 질량이 0일 경우 소멸 -> return
totalMass += newMass * 4; // 전체 질량에 새로운 질량*4개 더해줌

// 새로 생성된 파이어볼 4개 추가
for(int i = 0; i<4; i++){
// 모두 짝 or 홀이면 0,2,4,6 그렇지 않으면 1,3,5,7
int newDirection = isAllEvenOrOdd ? 2 * i : 2*i + 1;
graph[currY][currX].push_back({{idx, newMass}, {newSpeed, newDirection}});
}
}

void solve(int currY, int currX, int idx){
map<pair<int, int>, int> count;
for(int i = 0; i<graph[currY][currX].size(); i++){
pair<pair<int, int>, pair<int, int>> currBall = graph[currY][currX][i];

// 직전 회차에 위치한 공이 아니면 continue (이번 회차에 이동된 파이어볼과 구분)
if(currBall.first.first != idx-1) continue;
int nxtY = (currY + dy[currBall.second.second] * currBall.second.first) % n;
int nxtX = (currX + dx[currBall.second.second] * currBall.second.first) % n;
nxtY = nxtY < 0 ? nxtY + n : nxtY;
nxtX = nxtX < 0 ? nxtX + n : nxtX;

// 새로운 좌표에 위치시키기
currBall.first.first = idx;
graph[nxtY][nxtX].push_back(currBall);

// 좌표별 개수 갱신
if(count.find({nxtY, nxtX}) != count.end()) count[{nxtY, nxtX}] = 1;
else count[{nxtY, nxtX}]++;
}

// 새로 위치된 좌표들 중 두개 이상 있는 곳은 분리 -> 이걸 중간에 하면 안되고, 한 싸이클을 다 돈 뒤에 해야함..
// for(auto it = count.begin(); it != count.end(); it++){
// if(it->second + graph[it->first.first][it->first.second].size() == 2) continue;
// separate(it->first.first, it->first.second, idx);
// }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);

cin >> n >> m >> k;
for(int i = 0; i<m; i++){
int r, c, mass, d, s;
cin >> r >> c >> mass >> s >> d;
totalMass += mass;
// 파이어볼의 초기 좌표에 위치시키기, {0, 0}에서 시작하기 위해 r, c 값--
graph[--r][--c].push_back({{0, mass}, {s, d}});
}

//k번 이동
for(int i = 1 ; i <= k; i++){
for(int j = 0; j<n; j++){
for(int l = 0; l < n ; l++){
if(graph[j][l].empty()) continue;
solve(j, l, i);
}
}
// 회차 이동이 끝난 뒤 같은 칸에 두개 이상의 볼이 있는 경우 분리
for(int j = 0; j< n; j++){
for(int l = 0; l < n; l++){
if(graph[j][l].size() < 2) continue;
separate(j, l, i);
}
}
}
cout << totalMass <<"\n";
}
*/
