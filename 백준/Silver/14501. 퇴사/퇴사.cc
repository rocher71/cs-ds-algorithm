#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, maxMoney = 0;
int days[16], money[16], permArr[16];

void perm(int idx, int leftDays){
    if(idx == n){
        int sum = 0;
        for(int i = 0 ;i< n; i++){
//            cout << permArr[i] << " ";
            sum += permArr[i];
        }
//        cout << "\n";
        maxMoney = max(maxMoney, sum);
        return;
    }
    // 이미 작업중인 일이 있거나, 오늘 할 수 있는 일이 퇴사 후까지 이어질때
    if(leftDays > 0 || idx + days[idx] > n){
        permArr[idx] = 0;
        perm(idx + 1, leftDays - 1);
        return;
    }
    permArr[idx] = 0;
    perm(idx + 1, 0);
    permArr[idx] = money[idx];
    perm(idx + 1, days[idx] - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> days[i] >> money[i];
    }

    perm(0, 0);

    cout << maxMoney<< "\n";
}