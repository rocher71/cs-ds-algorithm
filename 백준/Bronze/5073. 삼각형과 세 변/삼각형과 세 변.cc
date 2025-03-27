#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int a, b, c;
int main(){

    while(true){
        v.clear();
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) return 0;

        if(a== b && b == c && c == a){
            cout << "Equilateral\n";
            continue;
        }


        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        if(v[0] + v[1] <= v[2]){
            cout << "Invalid\n";
            continue;
        }

        if(a == b || b == c || c == a){
            cout << "Isosceles\n";
            continue;
        }

        cout << "Scalene\n";
        
    }
}