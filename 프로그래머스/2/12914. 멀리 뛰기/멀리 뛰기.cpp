#include <string>
#include <vector>
#include<iostream>
using namespace std;

long long arr[2001];

long long solution(int n) {
    long long answer = 0;
    //n = 2000;
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i = 3; i<= n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567;;
    }
    
    //for(int i = 1; i<= n; i++) cout << arr[i] << " ";
    
    return arr[n];
}