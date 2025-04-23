#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int num) {
    int answer = -1;
    if(num ==1 ) return 0;
    long long ln = num;
    for(int i = 1; i<= 500; i++){
        if(ln % 2 == 0) ln /= 2;
        else ln = ln*3 + 1;
        //if(i >= 450) cout << i << " : " << ln << "\n";
        if(ln == 1)  return i;
    }
    return answer;
}