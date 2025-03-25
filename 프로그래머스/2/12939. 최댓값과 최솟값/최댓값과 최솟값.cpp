#include <string>
#include <vector>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

string solution(string s) {
    string answer = "", stringBuffer;
    istringstream ss(s);
    vector<int> v;
    
    while(getline(ss, stringBuffer, ' ')){
        v.push_back(stoi(stringBuffer));
    }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]) + " " + to_string(v[v.size()-1]);
    
    
    return answer;
}