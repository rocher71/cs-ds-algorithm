// 모르겠음
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, maxCnt;
int numbers[1001];
vector<pair<int, int>> cnt; // 개수, 이전 최대값

bool compare1(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    cin >> n;
    for(int i = 1; i<= n; i++) cin >> numbers[i];

    for(int i = 1; i<= n; i++){
        if(!cnt.empty()) sort(cnt.begin(), cnt.end(), compare1);
        bool isNew = true;
        for(int j = 0; j < cnt.size(); j++){
            if(cnt[j].second >= numbers[i]) continue;
            isNew = false;
            cnt[j].second = numbers[i];
            ++cnt[j].first;
            maxCnt = max(maxCnt, cnt[j].first);
            break;
        }
        if(!isNew) continue;
        cnt.push_back({1, numbers[i]});
    }

    cout << maxCnt << "\n";
}
