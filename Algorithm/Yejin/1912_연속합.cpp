#include <iostream>
#include <algorithm>
using namespace std;

int numbers[100001], sum[100001];
int n;

int main(){
    cin >> n;
    for(int i = 0; i< n; i++) cin >> numbers[i];

    sum[0] = numbers[0];
    //> 0 ? numbers[0] : 0; -> 이렇게 하면 첫항 음수일때 잘못 나옴.
    for(int i = 1; i< n; i++){
        sum[i] = numbers[i];
        if(numbers[i] + sum[i-1] > numbers[i]) sum[i] += sum[i-1];
    }

    sort(sum, sum + n);
    cout << sum[n-1] <<"\n";
}
