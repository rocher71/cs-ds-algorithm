//1806 부분합 <투포인터>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> v;

int main(){
    cin >> n >> s;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int left = 0, right = 0, sum = v[left], ans = 100001;
    while(right < n){
        if(sum < s){
            right++;
            sum += v[right];
            continue;
        }
        ans = min(right - left + 1, ans);
        sum -= v[left];
        left++;
    }
    if(ans == 100001){
        cout << 0;
        return 0;
    }
    cout << ans;
}
