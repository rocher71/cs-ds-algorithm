#include <string>
#include <vector>
#include<string>
using namespace std;

int solution(string my_string, string target) {
    int answer = 1;
    if(my_string.find(target) == string::npos) answer = 0;
    return answer;
}