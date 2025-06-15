#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for(auto & c : s){
        if(c == ' ') {
            answer += ' ';
            index = 0;
            continue;
        }
        
        if(index % 2 == 0) answer += toupper(c);
        else if(index % 2 != 0) answer += tolower(c);
        
        index++;
    }
    return answer;
}