#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cmath>
using namespace std;

int n, maxNum;
int moves[5], arr[21][21], firstArr[21][21];

void moveUp(){
    for(int i = 0; i < n; i++){
        deque<pair<int, bool>> dq; // {숫자, 합쳐진 숫자인지}
        for(int j = 0; j < n; j++){
            int curr = arr[j][i];
            if(curr == 0) continue;
            arr[j][i] = 0;
            if(dq.empty() || dq.back().second || dq.back().first != curr){
                dq.push_back({curr, false});
                continue;
            }
            
            dq.pop_back();
            dq.push_back({curr * 2, true});
        }
        
        for(int j = 0; j < dq.size(); j++){
            arr[j][i] = dq[j].first;
            maxNum = max(maxNum, dq[j].first);
        }
    }
}

void moveDown(){
    for(int i = 0; i < n; i++){
        deque<pair<int, bool>> dq;
        for(int j = n - 1; j >= 0; j--){
            int curr = arr[j][i];
            if(curr == 0) continue;
            
            arr[j][i] = 0;
            if(dq.empty() || dq.back().second || dq.back().first != curr){
                dq.push_back({curr, false});
                continue;
            }
            dq.pop_back();
            dq.push_back({curr * 2, true});
            // dq[dq.size() - 1] = {curr * 2, true};
        }
        // if(!dq.empty()) cout << "dq size : " << dq.size() << "\n";
        for(int j = 0 ; j < dq.size(); j++){
            // cout << dq[j].first << " " << dq[j].second << "\n";
            // cout << "n-j-1 : " << n - j - 1 << "\n";
            arr[n-j-1][i] = dq[j].first;
            maxNum = max(maxNum, dq[j].first);
        }
    }
}

void moveLeft(){
    // cout << "moveLeft\n";
    for(int i = 0; i < n; i++){
        deque<pair<int, bool>> dq;
        for(int j = 0; j < n; j++){
            int curr = arr[i][j];
            if(curr == 0) continue;
            
            arr[i][j] = 0;
            if(dq.empty() || dq.back().second || dq.back().first != curr){
                dq.push_back({curr, false});
                continue;
            }
            
            dq.pop_back();
            dq.push_back({curr * 2, true});
        }
        for(int j = 0; j < dq.size(); j++){
            arr[i][j] = dq[j].first;
            maxNum = max(maxNum, dq[j].first);
        }
    }
}

void moveRight(){
    
    for(int i =0 ;i < n;i++){
        deque<pair<int, bool>> dq;
        for(int j = n - 1; j >= 0; j--){
            int curr = arr[i][j];
            if(curr == 0) continue;
            
            arr[i][j] = 0;
            if(dq.empty() || dq.back().second || dq.back().first != curr){
                dq.push_back({curr, false});
                continue;
            }
            dq.pop_back();
            dq.push_back({curr * 2, true});
        }
        
        for(int j = 0; j < dq.size(); j++){
            arr[i][n - j - 1] = dq[j].first;
            maxNum = max(maxNum, dq[j].first);
        }
    }
}

void perm(int idx){
    // cout << idx << "\n";
    if(idx == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = firstArr[i][j];
            }
        }
        for(int i = 0; i < 5; i++){
            // cout << moves[i] << " ";
            if(moves[i] == 0) moveUp();
            else if(moves[i] == 1) moveDown();
            else if(moves[i] == 2) moveLeft();
            else moveRight();
        }
        // cout << "\n";
        // cout << "\nmaxNum : " << maxNum << "\n";
        return;
    }
    for(int i = 0 ; i < 4; i++){
        moves[idx] = i;
        perm(idx + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> firstArr[i][j];
        }
    }
    
    
    perm(0);
    // moveLeft();
    cout << maxNum << "\n";
}