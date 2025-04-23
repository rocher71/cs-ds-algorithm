#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n), conStr = "";
    vector<char> v;
    for(char c : str) v.push_back(c);
    sort(v.begin(), v.end());
    
    for(char c : v) cout << c << " ";
    
    for(int i = v.size() - 1; i >= 0; i--) conStr += v[i];
    
    answer = conStr[0] - '0';
    
    for(int i = 1; i< str.size(); i++){
        answer = answer * 10 + (conStr[i] - '0');
    }
    return answer;
}