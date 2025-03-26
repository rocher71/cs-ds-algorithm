#include <string>
#include <vector>
#include<iostream>
using namespace std;

long long int fibo[100001];

int solution(int n) {
    int answer = 0;
    fibo[1] = 1;
    for(int i = 2; i<= n; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) %1234567;
    }
    return fibo[n] % 1234567;
}