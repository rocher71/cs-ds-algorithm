//2805 나무 자르기 - binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

long long get_sum(int mid){
    long long sum = 0;
    for(int length : v){
        if(length - mid < 0) continue;
        sum += length - mid;
    }
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int left = 1, right = v[n-1];
    long long ans = 0, mid = 0;

    while (left <= right){
        mid = (left + right)/2;
        long long sum = get_sum(mid);

        if(sum < m){
            right = mid - 1;
            continue;
        }
        left = mid + 1;
        ans = max(ans, mid);
    }

    cout << ans;
}
