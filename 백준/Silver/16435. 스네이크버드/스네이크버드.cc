#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
vector<int> nums;

int main(){
    cin >> n >> l;
    for(int i  = 0; i< n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i< n ;i++){
        if(nums[i] > l) break;
        l++;
    }

    cout << l << "\n";

}