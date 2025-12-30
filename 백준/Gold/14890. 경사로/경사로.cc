#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int n, l;
int arr[101][101];
int constructed[101];

bool checkConstructed(int from, int contCnt, int constructStamp, int till){
    for(int i = from; i <= till; i++) if(constructed[i] == constructStamp) return true;
    for(int i = from; i <= till; i++){
        constructed[i] = constructStamp;
//        cout << constructed[i] << " ";
    }
//    cout << "\n";
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> l;
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0, constructStamp = 0;
    for(int rowCol = 0; rowCol < 2; rowCol++){
        for(int i = 0 ; i < n; i++){
            int prevNum = 0, prevContCnt = 0, currNum = 0, currContCnt = 0;
            bool cantGo = false, isChecking = false;
            if(rowCol == 0) prevNum = arr[i][0];
            else prevNum = arr[0][i];
            prevContCnt = 1;
            constructStamp++;
            for(int j = 1; j < n; j++){
                if(rowCol == 0) currNum = arr[i][j];
                else currNum = arr[j][i];

                // 이전, 현재 칸의 높이가 동일, 지을 수 있는지 확인중이었고 l 이상이라면
                if(currNum == prevNum && isChecking && prevContCnt + 1 == l){
                    cantGo = checkConstructed(j - prevContCnt, prevContCnt, constructStamp, j);
                    if(cantGo) break;
                    prevContCnt = 1;
                    isChecking = false;
                    continue;
                }

                // 이전, 현재 칸의 높이가 동일
                if(currNum == prevNum){
                    prevContCnt++;
                    continue;
                }

                if(isChecking && prevContCnt < l){
                    cantGo = true;
                    break;
                }

                // 다름
                // 차이가 1 초과라면 가지 못하는 길, 바로 break
                if(abs(prevNum - currNum) > 1){
                    cantGo = true;
                    break;
                }

                // 전 칸이 더 낮은 칸, 그러나 l 보다 수가 적다면 break
                if(prevNum < currNum && prevContCnt < l){
                    cantGo = true;
                    break;
                }

                // 전 칸이 낮은 칸, 수 l 이상
                if(prevNum < currNum){
                    // 낮은 칸에 이미 건설이 되어있는지 확인
                    cantGo = checkConstructed(j - l, prevContCnt, constructStamp, j - 1);
                    if(cantGo) break;
                    // 건설이 안되어있음 -> 건설 가능
                    prevNum = currNum;
                    prevContCnt = 1;
                    continue;
                }

                // 현재 칸이 낮은 칸
                isChecking = true;
                prevNum = currNum;
                prevContCnt = 1;
                cantGo = true;
                if(prevContCnt < l) continue;

                // 한칸짜리 확인
                cantGo = checkConstructed(j, prevContCnt, constructStamp, j);
                if(cantGo) break;
                isChecking = false;

            }
            if(cantGo) continue;
            ans++;
        }
    }


    cout << ans << "\n";
}

/*
 *
가로
1
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2

 3
 6 2
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2

 1
 6 3
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2

 5
 6 1
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
 */