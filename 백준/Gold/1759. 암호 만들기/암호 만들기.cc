#include<iostream>
#include<algorithm>
using namespace std;

int l, c;
char arr[16], letters[16];
bool visit[16];

bool hasLets(){
    int vowCnt = 0, conCnt = 0;
    for(int i = 0; i< l; i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') vowCnt++;
        else conCnt++;
    }
    if(vowCnt < 1 || conCnt < 2) return false;
    return true;
}

void perm(int idx, int prev){
    if(idx == l){
        if(!hasLets()) return;
        for(int i = 0; i< l; i++) cout << arr[i];
        cout << "\n";
        return;
    }
    for(int i =0 ;i < c; i++){
        if(visit[i] || i < prev) continue;
        arr[idx] = letters[i];
        visit[i] = true;
        perm(idx + 1, i);
        visit[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> l >> c;
    for(int i = 0; i< c; i++){
        cin >> letters[i];
    }

    sort(letters, letters + c);

    perm(0, 0);


}