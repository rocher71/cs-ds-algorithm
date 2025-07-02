#include<iostream>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    if(n % 2 == 0) cout << "CY\n";
    else cout << "SK\n";

    return 0;
}