#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

string solution(string s) {
    string answer = "";
    string tmp = "";
    
    for(int i = 0; i< s.size(); i++){
        if(s[i] != ' '){
            tmp += s[i];
            continue;
        }
        
        v.push_back(stoi(tmp));
        tmp.clear();
    }
     v.push_back(stoi(tmp));
    
    sort(v.begin(), v.end());
    
    answer = to_string(v[0]) + " " + to_string(v[v.size()-1]);
    
    return answer;
}