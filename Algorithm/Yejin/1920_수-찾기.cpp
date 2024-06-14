#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

bool binary_search(int length, int target){
    int low = 0, high = length-1;

    while (low <= high){
        int mid = (low + high)/2;

        if(v[mid] == target) return true;
        if(v[mid] < target){
            low = mid+1;
            continue;
        }
        if(v[mid] > target){
            high = mid - 1;
            continue;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i<n ;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for(int i = 0; i<m; i++){
        int target;
        cin >> target;
        cout << binary_search(n, target) <<"\n";
    }

}
