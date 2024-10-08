#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// studentInSeat[y][x] = y, x에 배정된 학생, studentFavs[a] = a학생이 좋아하는 4명 배열, order : 학생 순서(입력순), adjCnt[y][x] = y, x좌표에 인접한 빈자리
// ans[k] = 좋아하는 학생 k명과 인접해서 앉은 사람 수
int n, studentInSeat[31][31], studentFavs[401][4], order[401], adjCnt[31][31], ans[5];
int dy[4] = { 0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
pair<int, int> seatForStudents[401]; // [학생번호] = { y좌표, x좌표}

// stuNum 번호 학생을 currY, currX에 배치
void place(int stuNum, int currY, int currX){
    studentInSeat[currY][currX] = stuNum;
    seatForStudents[stuNum] = {currY, currX};

    // 인접한 자리 보며 adjCnt 배열 초기화
    for(int i = 0 ;i < 4; i++){
        int nxtY = currY + dy[i];
        int nxtX = currX + dx[i];
        if(nxtY < 1 || nxtX < 1 || nxtY > n || nxtX > n) continue;
        adjCnt[nxtY][nxtX]--;
    }
}

// 좋아하는 사람 없을 시 사용하는 함수, 빈자리 > Y좌표 > X좌표 순으로 확인 후 배치
void seatLeastRowCol(int curr){
    int maxAdj = -1, minY = 1000, minX = 1000;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(studentInSeat[i][j]
            || maxAdj > adjCnt[i][j]
            || (maxAdj == adjCnt[i][j] && minY < i)
            || (maxAdj == adjCnt[i][j] && minY == i && minX < j)) continue;
            maxAdj = adjCnt[i][j];
            minY = i;
            minX = j;

            // 만약 인접 빈자리가 4개 즉 최대값이라면 더 볼 것없이 I, j가 최소값이기 때문에 break
            if(maxAdj == 4) break;
        }
        if(maxAdj == 4) break;
    }
    place(curr, minY, minX);
}

void solve(int curr){
    queue<pair<int, int>> q;
    // curr 학생이 좋아하는 학생들의 자리를 q에 push
    for(int i = 0 ; i<4; i++){
        int favY = seatForStudents[studentFavs[curr][i]].first;
        int favX = seatForStudents[studentFavs[curr][i]].second;
        if(favY == 0 && favX == 0) continue; // 좋아하는 친구가 안 앉아있으면 continue
        q.push({favY, favX});
    }

    //q자리 사방의 자리를 후보로 두고, 각 자리에 인접한 좋아하는 학생 수 카운트 -> 각 자리별 score 매김
    map<pair<int, int>, int> seatScore;
    while (!q.empty()){
        int favY = q.front().first;
        int favX = q.front().second;
        q.pop();

        for(int i = 0 ;i <4; i++){
            int nxtY = favY + dy[i];
            int nxtX = favX + dx[i];
            if(nxtY < 1 || nxtX < 1 || nxtY > n || nxtX > n || studentInSeat[nxtY][nxtX]) continue;
            // 자리별 점수 매기기, 처음나온 자리면 1, 이전에 이미 나온 자리면 ++
            if(seatScore.find({nxtY, nxtX}) == seatScore.end()) seatScore[{nxtY, nxtX}] = 1; // 처음 나온 자리면 점수 1
            else seatScore[{nxtY, nxtX}]++;
        }
    }
    
    // 후보자리 중 근접 좋아하는 학생 수 > 근접 빈자리 > y좌표 > x좌표 순으로 배치
    int maxScore = -1, leastY = 100, leastX = 100, mostAdjCnt = 0;
    for(map<pair<int, int>, int>::iterator it = seatScore.begin(); it != seatScore.end(); it++){
        int nxtY = it->first.first;
        int nxtX = it->first.second;
        int nxtScore = it->second;

        if(studentInSeat[nxtY][nxtX]) continue;
        if(nxtScore < maxScore) continue;
        
        // 동일 score 인 경우 인접 빈자리 수 비교 후 배치
        if(nxtScore == maxScore && mostAdjCnt < adjCnt[nxtY][nxtX]){
            maxScore = nxtScore;
            leastY = nxtY;
            leastX = nxtX;
            mostAdjCnt = adjCnt[leastY][leastX];
            continue;
        }
        
        // 조건 맞지 않은 경우 continue
        if(nxtScore == maxScore && mostAdjCnt > adjCnt[nxtY][nxtX]) continue;
        if(nxtScore == maxScore && (nxtY > leastY)) continue;
        if(nxtScore == maxScore && nxtY == leastY && (nxtX > leastX)) continue;

        // 점수 > y > x 순 배치
        maxScore = nxtScore;
        leastY = nxtY;
        leastX = nxtX;
        mostAdjCnt = adjCnt[leastY][leastX];
    }
    
    // 좋아하는 학생이 없거나 동일 score 자리 여러개 시 근접 빈 자리가 > row > col 순 위치에 앉히기
    if(maxScore == -1){
        seatLeastRowCol(curr);
        return;
    }
    place(curr, leastY, leastX);
}

// 최종 정답 출력용
// 각 자리 학생 별 만족도 계산
void adjFavCnt(int curr){
    int cnt = 0;
    // 연산 횟수 줄이기 위해 curr 학생이 좋아하는 학생일 시 favList[x] = true
    // ex. curr = a, favList[b] = true -> b는 a가 좋아하는 학생임
    bool favList[401];
    fill(favList, favList+401, false);
    for(int i = 0 ; i< 4; i++) favList[studentFavs[curr][i]] = true;

    // curr 학생의 인접 학생들 중 좋아하는 학생 수 계산
    int currY = seatForStudents[curr].first;
    int currX = seatForStudents[curr].second;
    for(int i = 0 ;i < 4; i++){
        int nxtY = currY + dy[i];
        int nxtX = currX + dx[i];
        if(nxtY < 1 || nxtX < 1 || nxtY > n || nxtX > n) continue;
        int nxtStudent = studentInSeat[nxtY][nxtX];
        if(favList[nxtStudent]) cnt++;
    }
    ans[cnt]++;
}

int main(){
    cin >> n;
    for(int i = 1 ;i <= n*n ; i++){
        int num;
        cin >> num;
        order[i] = num;
        for(int j = 0 ; j< 4; j++){
            cin >> studentFavs[num][j];
        }
    }

    // 각 자리별로, 인접 빈자리 수 초기화
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            int emptyAdj = 4; //기본 4
            // 상하좌우 중 벽이 있을 시 1씩 차감
            if(i == 1) emptyAdj--;
            if(j == 1) emptyAdj--;
            if(i == n) emptyAdj--;
            if(j == n) emptyAdj--;
            adjCnt[i][j] = emptyAdj;
        }
    }

    // 조건상 첫번째 학생은 무조건 2, 2에 배치됨
    place(order[1], 2, 2);
    
    // 각 학생 배치
    for(int i = 2 ; i <= n * n; i++) solve(order[i]);
    
    // 배치 끝난 뒤 만족도 계산
    for(int i = 1; i<=n*n; i++) adjFavCnt(i);
    
    // 만족도 최종 계산
    cout << ans[1] + ans[2] * 10 + ans[3] * 100 + ans[4] * 1000 <<"\n";

}
