#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[40001];
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int len = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        if (idx == len) {
            lis.push_back(arr[i]);
            len++;
            continue;
        }

        lis[idx] = arr[i];
    }

    cout << lis.size() << "\n";
}