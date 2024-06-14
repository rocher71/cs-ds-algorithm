//1654 랜선자르기, binary search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

unsigned int k, n;
vector<unsigned int> v;

unsigned int get_divisible(unsigned int length){
    unsigned int divisible = 0;
    for(unsigned int givenSize : v){
        divisible += givenSize / length;
    }
    return divisible;
}

int main(){
    cin >> k >> n;
    for(int i = 0; i<k ; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    unsigned int left = 1, right = v[k-1], ans = 0;

    while(left<= right){
        unsigned int mid = (left + right)/2;
        unsigned int divisible = get_divisible(mid);

        if(divisible < n){
            right = mid -1;
            continue;
        }
        ans = max(ans, mid);
        left = mid + 1;
    }

    cout << ans;
}
