#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<char> cs;
    char c;
    for(int i = 0; i< my_string.size(); i++){
        if(my_string[i] >= 'a' && my_string[i] <= 'z') c = my_string[i];
        else c = my_string[i] + ('a' - 'A');
        cs.push_back(c);
    }
    sort(cs.begin(), cs.end());
    for(char c : cs) answer += c;
    return answer;
}