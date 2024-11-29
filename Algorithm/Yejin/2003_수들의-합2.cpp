//2003 수들의 합2 <투 포인터>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int main(){

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int start = 0, end = 0, sum = v[0], answer = 0;
    while(end < n){
//        sum = (start == end) ? v[start] : v[start] + v[end];
        if(sum < m){
            end++;
            sum += v[end];
            continue;
        }
        if(sum > m){
            sum -= v[start];
            start++;
            continue;
        }
        answer++;
        end++;
        sum = sum - v[start];
        if(end < n) sum += v[end];
        start++;
    }

    cout << answer;
}
