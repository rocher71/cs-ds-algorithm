#include <string>
#include <vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long pInt = stol(p);
    for(int i = 0; i<= t.size() - p.size(); i++){
        // cout << t.substr(i, p.size()) << " ";
        long long sub = stol(t.substr(i, p.size()));
        if(sub <= pInt) answer++;
    }
    return answer;
}