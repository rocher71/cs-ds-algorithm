#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long n;

int main(){
    cin >> n;
    long long int q = sqrt(n);

    if( q * q < n) ++q;
    cout << q;

    return 0;

}
