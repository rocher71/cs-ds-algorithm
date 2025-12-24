#include<iostream>
#include<climits>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int cmdCnt;
vector<deque<int>> wheels;

void rotate(int toRotate, int src, int dir){
    int leftAffect = wheels[toRotate][6];
    int rightAffect = wheels[toRotate][2];

    // 시계 방향 회전
    if(dir == 1){
        wheels[toRotate].push_front(wheels[toRotate][7]);
        wheels[toRotate].pop_back();
    } else { // 반시계
      wheels[toRotate].push_back(wheels[toRotate][0]);
      wheels[toRotate].pop_front();
    }

    int left = toRotate - 1;
    int right = toRotate + 1;
    int affectDir = dir == 1 ? -1 : 1;

    if(left != src && left >= 0 && left <= 3 && leftAffect != wheels[left][2]) rotate(left, toRotate, affectDir);
    if(right != src && right >= 0 && right <= 3 && rightAffect != wheels[right][6]) rotate(right, toRotate, affectDir);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 4; i++){
        deque<int> dq;
        string str;
        cin >> str;
        for(int j= 0; j < 8; j++) dq.push_back(str[j] - '0');
        wheels.push_back(dq);
    }
    cin >> cmdCnt;
    for(int i = 0 ; i< cmdCnt; i++){
        int num, dir;
        cin >> num >> dir;
        rotate(num - 1, num - 1, dir);
//        cout << "\n cmd : " << num << " " << dir << "\n";
//        for(int j = 0; j < 4; j++){
//            for(int k = 0; k < 8; k++) cout << wheels[j][k];
//            cout << "\n";
//        }
    }

    int ans = 0;
    if(wheels[0][0] == 1) ans += 1;
    if(wheels[1][0] == 1) ans += 2;
    if(wheels[2][0] == 1) ans += 4;
    if(wheels[3][0] == 1) ans += 8;

    cout << ans << "\n";
}