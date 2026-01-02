#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int n, k, zeroCnt;
deque<int> belt;
deque<bool> isRobotOnBelt;
deque<int> robotInfo;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    for(int i = 0; i < 2 * n; i++){
        int num;
        cin >> num;
        belt.push_back(num);
        if(i < n) isRobotOnBelt.push_back(0);
        
    }
    
    int time = 0;
    while(zeroCnt < k){
        time++;
        // cout << "\ntime : " << time << "\n1.벨트회전\n";
        // 1. 벨트 회전
        belt.push_front(belt.back());
        belt.pop_back();
        
        // for(int i = 0; i< 2 * n; i++) cout << belt[i] << " ";
        // cout << "\n";
        
        // for(int i = 0; i < n; i++) cout << isRobotOnBelt[i] << " ";
        
        // 2. 로봇 벨트와 회전
        isRobotOnBelt.pop_back();
        isRobotOnBelt.push_front(false);
        // cout << "\nisRobotOnBelt.size() : " << isRobotOnBelt.size() << "\n";
        // cout << "팝백 후 : ";
        // for(int i = 0; i < n; i++) cout << isRobotOnBelt[i] << " ";
        int haveToPop = 0;
        for(int i = 0; i< robotInfo.size(); i++){
            
            robotInfo[i]++;
            // 내리는 칸에 도착하면 내림
            if(robotInfo[i] < n - 1) continue;
            haveToPop++;
            isRobotOnBelt[n - 1] = 0;
        }
        for(int i = 0; i< haveToPop; i++) robotInfo.pop_front();
        // cout << "\n2.로봇 벨트와 회전\n";
        // for(int i = 0; i < n; i++) cout << isRobotOnBelt[i] << " ";
        // if(time <= 3){
        //     cout << "\nrobotLoc : ";
        //     for(int i = 0; i< robotInfo.size(); i++){
        //         cout << robotInfo[i] << " ";
        //     }    
        //     cout << "\n";
        // }
        // cout << "\n\n";
        
        
        // 3. 로봇 이동
        haveToPop = 0;
        for(int i = 0; i < robotInfo.size(); i++){
            int currLoc = robotInfo[i];
            isRobotOnBelt[currLoc] = true;
            int nextLoc = currLoc + 1;
            // if(time <= 5) {cout << "currLoc, nextLoc : " 
            //     << currLoc << " " << nextLoc << "\n";}
            
            if(isRobotOnBelt[nextLoc] || belt[nextLoc] == 0) continue;
            
            isRobotOnBelt[currLoc] = false;
            isRobotOnBelt[nextLoc] = true;
            robotInfo[i] = nextLoc;
            if(--belt[nextLoc] == 0) zeroCnt++;
            
            if(nextLoc != n - 1) continue;
            
            // 내리는 칸 도달한 로봇
            haveToPop++;
            isRobotOnBelt[nextLoc] = false;
        }
        for(int i = 0;i < haveToPop; i++) robotInfo.pop_front();
        // cout << "\n3. 로봇 이동 후\n";
        // for(int i = 0; i< 2 * n; i++) cout << belt[i] << " ";
        // cout << "\n";
        // for(int i = 0; i < n; i++) cout << isRobotOnBelt[i] << " ";
        // cout << "\n\n";
        
        // 4. 첫 위치에 로봇 추가
        if(belt[0] == 0) continue;
        
        isRobotOnBelt[0] = true;
        robotInfo.push_back(0);
        if(--belt[0] == 0) zeroCnt++;
        
        // cout << "\n4. 첫 위치에 로봇 추가 후\n";
        // for(int i = 0; i< 2 * n; i++) cout << belt[i] << " ";
        // cout << "\n";
        // for(int i = 0; i < n; i++) cout << isRobotOnBelt[i] << " ";
        // cout << "\n\n";
        
        // if(time <= 3){
        //     for(int i = 0; i< robotInfo.size(); i++){
        //         cout << "robotLoc : " << robotInfo[i] << " ";
        //     }    
        //     cout << "\n";
        // }
        
        if(zeroCnt >= k) break;
    }
    
    cout << time << "\n";
}




/*
3 5
1 1 1 1 1 1

time : 1
1.벨트회전
1 1 1 1 1 1 
0 0 0 
isRobotOnBelt.size() : 1
팝백 후 : 0 0 0 
2.로봇 벨트와 회전
0 0 0 
robotLoc : 



3. 로봇 이동 후
1 1 1 1 1 1 
0 0 0 


4. 첫 위치에 로봇 ��가 후
0 1 1 1 1 1 
1 0 0 

robotLoc : 0 

time : 2
1.벨트회전
1 0 1 1 1 1 
1 0 0 
isRobotOnBelt.size() : 1
팝백 후 : 0 1 156 
2.로봇 벨트와 회전
0 1 156 
robotLoc : 1 


currLoc, nextLoc : 1 2

3. 로봇 이동 후
1 0 1 1 1 1 
0 1 156 


4. 첫 위치에 로봇 추가 후
0 0 1 1 1 1 
1 1 156 

robotLoc : 1 robotLoc : 0 

time : 3
1.벨트회전
1 0 0 1 1 1 
1 1 156 
isRobotOnBelt.size() : 1
팝백 후 : 0 1 1 
2.로봇 ��트와 회전
0 1 0 
robotLoc : 1 


currLoc, nextLoc : 1 2

3. 로봇 이동 후
1 0 0 1 1 1 
0 1 0 


4. 첫 위치에 로봇 추가 후
0 0 0 1 1 1 
1 1 0 

robotLoc : 1 robotLoc : 0 

time : 4
1.벨트회전
1 0 0 0 1 1 
1 1 0 
isRobotOnBelt.size() : 1
팝백 후 : 0 1 1 
2.로봇 벨트와 회전
0 1 0 

currLoc, nextLoc : 1 2

3. 로봇 이동 ��
1 0 0 0 1 1 
0 1 0 


4. 첫 위치에 로봇 추가 후
0 0 0 0 1 1 
1 1 0 


time : 5
1.벨트회전
1 0 0 0 0 1 
1 1 0 
isRobotOnBelt.size() : 1
팝백 후 : 0 1 1 
2.로봇 벨트와 회전
0 1 0 

currLoc, nextLoc : 1 2

3. 로봇 이동 후
1 0 0 0 0 1 
0 1 0 


4. 첫 위치에 로봇 추가 후
0 0 0 0 0 1 
1 1 0 

5
*/

