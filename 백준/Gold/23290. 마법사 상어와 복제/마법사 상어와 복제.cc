#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<string>
using namespace std;

int sharkY, sharkX, m, s;
int fishes[4][4][8], newFishes[4][4][8], sharkPerm[3];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    sharkDy[5] = {0, -1, 0, 1, 0}, sharkDx[5] = {0, 0, -1, 0, 1};
vector<string> sharkRoutes;
queue<int> smells[4][4];

void perm(int idx){
    if(idx == 3){
        int route = sharkPerm[0] * 100 + sharkPerm[1] * 10 + sharkPerm[2];
        sharkRoutes.push_back(to_string(route));
        return;
    }
    for(int i = 1; i <= 4; i++){
        sharkPerm[idx] = i;
        perm(idx + 1);
    }
}

void moveFish(){
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            for(int d = 0; d < 8; d++){
                if(fishes[y][x][d] == 0) continue;

                bool moved = false;
                int nextY, nextX;
                for(int i = 0; i < 8; i++){
                    int nextD = (d - i + 8) % 8;
                    nextY = y + dy[nextD];
                    nextX = x + dx[nextD];

                    if(nextY < 0 || nextX < 0 || nextY >= 4 || nextX >= 4) continue;
                    if(nextY == sharkY && nextX == sharkX) continue;
                    if(!smells[nextY][nextX].empty()) continue;

                    newFishes[nextY][nextX][nextD] += fishes[y][x][d];
                    moved = true;
                    break;
                }

                if(moved) continue;
                newFishes[y][x][d] += fishes[y][x][d];
            }
        }
    }
}

void moveShark(int times){
    int maxFishCnt = -1, idx = 0, minPossibleIdx = -1;
    for(int i = 0; i< 64; i++){
        int fishCnt = 0;
        bool cantGo = false;
        int currY = sharkY, currX = sharkX;
        unordered_set<string> us;
        for(int j = 0; j < 3; j++){
            int d = sharkRoutes[i][j] - '0';
            int nextY = currY + sharkDy[d];
            int nextX = currX + sharkDx[d];

            if(nextY < 0 || nextX < 0 || nextY >= 4 || nextX >= 4){
                cantGo = true;
                break;
            }

            string str = to_string(nextY) + to_string(nextX);
            currY = nextY;
            currX = nextX;

//            cout << "str : " << str << "\n";
            if(us.find(str) != us.end()) continue; // 이미 갔던 칸이면 continue;

            for(int k = 0; k < 8; k++) fishCnt += newFishes[nextY][nextX][k];

            us.insert(str);
        }

        if(cantGo || fishCnt <= maxFishCnt) continue;

        if(minPossibleIdx == -1) minPossibleIdx = i;
        maxFishCnt = fishCnt;
        idx = i;
        continue;
    }

//    cout << "time : " << times << ", sharkRoute : " << sharkRoutes[idx] << "\n";
    if(maxFishCnt == 0) idx = minPossibleIdx;
    int currY = sharkY, currX = sharkX;
    for(int i = 0; i < 3; i++){
        int d = sharkRoutes[idx][i] - '0';
        currY += sharkDy[d];
        currX += sharkDx[d];
        for(int j = 0; j < 8; j++){
            if(newFishes[currY][currX][j] == 0) continue;
            newFishes[currY][currX][j] = 0;
            smells[currY][currX].push(times);
        }
    }
    sharkY = currY;
    sharkX = currX;
}

void removeSmells(int times){
    if(times <= 2) return;
    for(int i = 0; i < 4; i++){
        for(int j =0 ; j < 4; j++){
            if(smells[i][j].empty() || times - smells[i][j].front() < 2) continue;
            while(times - smells[i][j].front() >= 2){
                smells[i][j].pop();
                if(smells[i][j].empty()) break;
            }
        }
    }
}

void dupFishes(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                if(newFishes[i][j][k] == 0) continue;
                fishes[i][j][k] += newFishes[i][j][k];
                newFishes[i][j][k] = 0;
            }
        }
    }
}

void print(int times, string str){
    return;
    cout << "times : " << times << ", step : " << str << "\nShark : " << sharkY << ", " << sharkX << "\nFishes\n";
//    return;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = 0;
            for(int k = 0; k < 8; k++) sum += fishes[i][j][k];
            cout << sum << " ";
        }
        cout << "\n";
    }

    cout << "New Fishes\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = 0;
            for(int k = 0; k < 8; k++) sum += newFishes[i][j][k];
            cout << sum << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> m >> s;
    for(int i = 0; i < m; i++){
        int y, x, d;
        cin >> y >> x >> d;
        fishes[--y][--x][--d]++;
    }
    cin >> sharkY >> sharkX;
    sharkY--;
    sharkX--;

    perm(0);

//    cout << sharkRoutes.size() << "\n";
//    for(int i = 0; i < sharkRoutes.size(); i++) cout << i << " : " << sharkRoutes[i] << "\n";

    for(int times = 1; times <= s; times++){
        print(times, "Initial");
        // 1. 물고기 복제

        // 2. 물고기 이동
        moveFish();
        print(times, "After moveFish()");

        // 3. 상어 이동
        moveShark(times);
        print(times, "After moveShark");

        // 4. 2턴 전 냄새 사라짐
        removeSmells(times);
        print(times, "After removeSmells()");

        // 5. 물고기 복제
        dupFishes();
        print(times, "After dupFishes()");

    }

    int cnt = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                cnt += fishes[i][j][k];
            }
        }
    }

    cout << cnt << "\n";

}