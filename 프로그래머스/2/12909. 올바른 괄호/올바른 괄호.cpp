#include<string>
#include <iostream>
#include<stack>
using namespace std;

stack<int> st;

bool solution(string s)
{
    bool answer = true;

    for(int i = 0; i< s.size(); i++){
        if(s[i] == '('){
            st.push(1);
            continue;
        }
        
        if(st.empty()) return false;
        st.pop();
    }
    
    if(!st.empty()) return false;

    return answer;
}