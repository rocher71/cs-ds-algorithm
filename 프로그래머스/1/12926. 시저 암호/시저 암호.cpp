#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s, int n) {
    int a = 'a', b = 'A';
    //cout << a << " " << b << " ";
    string answer = "";
    for(char c : s){
        int num = c;
       // cout << (num + n) << " " << (num + n) - 26 << " ";
        if(c == ' ') answer += ' ';
        else if(c >= 'a' && c <= 'z') answer += (num + n > 'z') ? num + n - 26 : num + n;
        else answer += (num + n > 'Z') ? num + n - 26 : num + n;
    }
    return answer;
}