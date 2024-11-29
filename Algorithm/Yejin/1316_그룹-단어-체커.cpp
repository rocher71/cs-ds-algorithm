#include <iostream>
#include <vector>
using namespace std;

int cnt, ans;
vector<string> words;
int letters[26];

bool isGroup(string str){
    fill_n(letters, 26, false);
    letters[str[0]-'a']++;
    for(int i = 1; i< str.length(); i++){
        if(str[i] != str[i-1] && letters[str[i] - 'a'] >= 1) return false;
        letters[str[i] - 'a']++;
    }
    return true;
}

int main(){
    cin >> cnt;
    for(int i = 0 ; i< cnt; i++){
        string str;
        cin >> str;
        words.push_back(str);
    }

    for(string str : words){
        if(isGroup(str)) ans++;
    }

    cout << ans << "\n";
}
