/*
// 604ms 코드
#include <iostream>
#include <map>
using namespace std;

int n, m;
int arr[500001];
map<int, int> numbers;

int main(){
    cin.tie(0); ios::sync_with_stdio(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        if(numbers.find(a) == numbers.end()){
            numbers.insert({a, 1});
            continue;
        }
        numbers[a]++;
    }
    cin >> m;
    for(int i = 0; i< m; i++){
        int num;
        cin >> num;
        if(numbers.find(num) == numbers.end()){
            cout << "0 ";
            continue;
        }
        cout << numbers[num] << " ";
    }
}

*/

// 260ms 코드
#include <iostream>
#include <map>
using namespace std;

int n, m;
int arr[20000001];
// 음수도 있으므로 범위 +10000000

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i< n; i++){
        int a;
        cin >> a;
        arr[a + 10000000]++;
    }

    cin >> m;
    for(int i = 0; i< m; i++){
        int a;
        cin >> a;
        cout << arr[a + 10000000] << " ";
    }
    cout << "\n";
}
