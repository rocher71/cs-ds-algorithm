#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s) {
    string answer = "", tmp= "";
    
    for(int i = 0; i< s.size(); i++){
        if(s[i] != ' '){
            // 대문자는 모두 소문자로 처리 후 tmp에 넣어줌
            if(s[i] >= 'A' && s[i] <= 'Z') tmp += s[i] + 32;
            else tmp+= s[i];
            continue;
        }
        
        // 앞 글자는 대무자 처리 후 answer에 추가
        if(tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] = tmp[0] - 32;
        answer += tmp + " ";
        
        tmp.clear();
    }
    // 마지막 단어 처리
    if(tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] = tmp[0] - 32;
    answer += tmp;
    
    
    
    
    
    return answer;
}