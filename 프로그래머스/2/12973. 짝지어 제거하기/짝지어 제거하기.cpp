#include <iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> st;

int solution(string s)
{
    int answer = 0;

    for(int i = 0; i< s.size(); i++){
        int curr = s[i] - 'a';
        
        if(st.empty()){
            st.push(curr);
            continue;
        }
        
        if(st.top() == curr){
            st.pop();
            continue;
        }
        
        st.push(curr);
    }
    
    return st.empty();
}