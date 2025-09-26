#include <string>
#include <vector>
#include<unordered_set>
#include<iostream>
using namespace std;
unordered_multiset<string> s;

string solution(vector<string> participant, vector<string> completion) {
    for(string str : participant) s.insert(str);
    
    for(string str : completion) s.erase(s.find(str));
    
    string answer = "";
    for(auto it : s) cout << it << " ";
    for(auto it : s) answer = it;
    return answer;
}