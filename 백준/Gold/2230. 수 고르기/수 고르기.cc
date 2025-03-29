#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >>  n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0, right = 0, maxDiff = INT_MAX;
    int maxLeft, maxRight, diff;
    while(right < n){
        diff = arr[right] - arr[left];

        if(diff == m) {
            maxDiff = m;
            break;
        }

        if(diff > m && diff < maxDiff){
            maxDiff = diff;
            maxLeft = left;
            maxRight = right;
        }

        if(diff < m) right++;
        else left++;
    }

    cout << maxDiff << "\n";
}