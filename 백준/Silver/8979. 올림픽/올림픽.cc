#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<pair<pair<int, int>, pair<int, int>>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int targetGold, targetSilver, targetBronze;
    for(int i = 0; i < n; i++){
        int countryNum, gold, silver, bronze;
        cin >> countryNum >> gold >> silver >> bronze;
        v.push_back({{gold, silver}, {bronze, countryNum}});
        if(countryNum != k) continue;
        targetGold = gold;
        targetSilver = silver;
        targetBronze = bronze;
    }
    sort(v.begin(), v.end(), greater<>());

    int targetIdx, samePlaceCnt = 0;
    for(int i = 0 ;i< n; i++){
        int currGold = v[i].first.first, currSilver = v[i].first.second, currBronze = v[i].second.first, currCountry = v[i].second.second;

        if(currCountry == k){
            targetIdx = i;
            break;
        }
        if(currGold != targetGold || currSilver != targetSilver || currBronze != targetBronze) continue;
        samePlaceCnt++;
    }

    if(samePlaceCnt == 0) cout << targetIdx + 1 << "\n";
    else cout << targetIdx + 1 - samePlaceCnt << "\n";
}
/*
 *
 * 1 2 2 2 4
 *
 *
5 3
1 1 2 0
2 0 1 0
3 0 1 0
4 0 0 1
5 0 1 0
 */