#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> lis;
int lastLen[100001];
bool isLis[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a, b });
    }

    sort(arr.begin(), arr.end());

    int len = 0, maxLen = 1;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i].second) - lis.begin();
        lastLen[i] = idx + 1;
        maxLen = max(lastLen[i], maxLen);
        if (idx == len) {
            lis.push_back(arr[i].second);
            len++;
            continue;
        }
        lis[idx] = arr[i].second;
    }


    for (int i = n - 1; i >= 0; i--) {
        if (lastLen[i] != maxLen) continue;
        isLis[i] = true;
        maxLen--;
    }

    cout << n - lis.size() << "\n";
    for (int i = 0; i < n; i++) {
        if (isLis[i]) continue;
        cout << arr[i].first << "\n";
    }

    return 0;

}