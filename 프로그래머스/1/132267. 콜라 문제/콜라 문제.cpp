#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int giveCnt, int getCnt, int haveCnt) {
    int answer = 0;
    while(haveCnt>= giveCnt){
        answer += haveCnt / giveCnt * getCnt;
        haveCnt = (haveCnt / giveCnt * getCnt) + (haveCnt % giveCnt);
        // cout << answer << " " << haveCnt << "\n";
    }
    
    return answer;
}