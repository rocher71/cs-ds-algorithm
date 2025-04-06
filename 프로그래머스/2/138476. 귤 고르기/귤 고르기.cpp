#include <string>
#include <vector>
#include<iostream>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

int arr[10000001];
int maxV = 0, minV = INT_MAX;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int t : tangerine){
        arr[t]++;
        if(t > maxV) maxV = t;
        if(t < minV) minV = t;
    }
    
    sort(arr + 1, arr + maxV + 1);
    
    //for(int i = 1; i< maxV + 1; i++) cout << arr[i] << " ";
    //cout << "\n";
    
    while(k > 0){
        //cout << "=============\n";
        //cout << k << " " << maxV << " \n";
        k -= arr[maxV--];
        //cout << k << " " << maxV << " \n";
        //cout << "=============\n";
        answer++;
    }
    
    return answer;
}