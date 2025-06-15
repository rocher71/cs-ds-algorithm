#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool isNotZero = false;
    for(char c : n_str){
        if(isNotZero){
            answer += c;
            continue;
        }
        if(c == '0') continue;
        isNotZero = true;
        answer += c;
    }
    return answer;
}