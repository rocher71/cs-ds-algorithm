#include <string>
#include <vector>
#include<iostream>
#include<bitset>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCnt = 0, cnt = 0;
    string noZero = "", binary = "";
    while(binary != "1"){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                noZero += '1';
                continue;
            }
            zeroCnt++;
        }
        
        int c = int (noZero.size());
        binary = bitset<100> (c).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        cnt++;
        
        if(binary == "1") break;
        s = binary;
        noZero = "";
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    return answer;
}