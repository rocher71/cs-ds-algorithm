#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int tc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    int t, cnt = 0, num;
    while(tc--){
        vector<int> v;
        cin >> t >> num;
        v.push_back(num);
        cnt = 0;
        for(int i = 1; i< 20; i++){
            cin >> num;
            int idx = upper_bound(v.begin(), v.end(), num) - v.begin();
            if(idx == i){
                v.push_back(num);
                continue;
            }
            cnt += i - idx;
            v.insert(v.begin() + idx, num);
        }

        cout << t << " " << cnt << "\n";

    }


}