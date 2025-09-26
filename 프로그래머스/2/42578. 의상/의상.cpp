#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
    for(int i = 0; i< clothes.size(); i++){
        if(m.find(clothes[i][1]) == m.end()) m.insert({clothes[i][1], 1});
        else m[clothes[i][1]]++;
    }
    int answer = 1;
    for(auto it : m) answer *= it.second + 1;
    return answer - 1;
}