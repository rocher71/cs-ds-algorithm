#include <string>
#include <vector>

using namespace std;
int loc[27];

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(-1);
    
    for(int i = 0; i <= 25; i++) loc[i] = -1;
    loc[s[0] - 'a'] = 0;
    
    for(int i = 1; i < s.length(); i++){
        if(loc[s[i] - 'a'] == -1) answer.push_back(-1);
        else answer.push_back(i - (loc[s[i] - 'a']));
        loc[s[i] - 'a'] = i;
    }
    return answer;
}