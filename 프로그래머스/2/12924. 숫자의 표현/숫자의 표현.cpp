#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int sum[10001];

int solution(int n) {
    int answer = 0, from = 0;
    sum[1] = 1;
    for(int i = 2; i<= n; i++){
        sum[i] = sum[i-1] + i;
        // if(sum[i] <= n) continue;
        // from = i;
        // break;
    }
    
    for(int i = n; i >= 1; i--){
        int subt = sum[i] - n;
        if(binary_search(sum, sum + n, subt)) answer++;
    }
    
    return answer;
}