#include <string>
#include <vector>
#include<bitset>
#include<iostream>
using namespace std;

int getOneCnt(string str){
    int cnt = 0;
    for(int i = 0; i< str.size(); i++) if(str[i] == '1') cnt++;
    return cnt;
}


int solution(int n) {
    int answer = 0;
    
    string nBinary = bitset<100> (n).to_string();
    nBinary.erase(0, nBinary.find_first_not_of('0'));
    int nCnt = getOneCnt(nBinary);
    int num = n + 1;
    while(true){
        string newBinary = bitset<100> (num).to_string();
        newBinary.erase(0, newBinary.find_first_not_of('0'));
        int cnt = getOneCnt(newBinary);
        if(cnt == nCnt) break;
        num++;
    }
    
    
    return num;
}