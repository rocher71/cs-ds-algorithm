#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

int n;
long long minVals[3], arr[5001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i< n; i++) cin >>arr[i];
    sort(arr, arr + n);

    long long minSum = 3e9;
    for(int i = 0; i< n; i++){
        long long num = arr[i];
        long long sum = 0;
        int left = i + 1, right = n - 1;

        while(left < right){
            sum = num + arr[left] + arr[right];
            //cout << num << " " << arr[left] << " " << arr[right] << " : " << sum<< "\n";

            if(sum == 0){
                minVals[0] = num;
                minVals[1] = arr[left];
                minVals[2] = arr[right];
                minSum = 0;
                break;
            }
            if(abs(sum) < abs(minSum)) {
                minVals[0] = num;
                minVals[1] = arr[left];
                minVals[2] = arr[right];
                minSum = sum;
            }

            if(sum < 0) left++;
            /*{
                if(left + 1 == i) left += 2;
                else left++;
            }*/
            else {
                //if(right - 1 == i) right -= 2;
                right--;
            }
        }
        if(minSum == 0) break;
    }

    sort(minVals, minVals + 3);
    cout << minVals[0] << " " << minVals[1] << " " << minVals[2] << "\n";
}