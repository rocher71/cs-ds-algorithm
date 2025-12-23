#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int row, col;
long long arr[502][502];
long long sum[502][502];

// 직사각형의 누적합을 리턴하는 함수
long long getRectSum(int i, int j, int height, int width){
    if(i - height < 0 || j - width < 0) return 0;
//    cout << sum[i][j] - sum[i - height][j] - sum[i][j - width] + sum[i - height][j - width] << "\n";
    return sum[i][j] - sum[i - height][j] - sum[i][j - width] + sum[i - height][j - width];
}

// 테르노미노의 누적합을 리턴하는 함수
long long getTerSum(long long rectSum,int i, int j, int a, int b, int c, int d){
    return rectSum - arr[i - a][j - b] - arr[i - c][j - d];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 배열 입력 및 누적합 배열 초기화
    cin >> row >> col;
    for(int i = 1; i<= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
//    cout << "\n";
//    for(int i = 1; i<= row; i++){
//        for(int j = 1 ; j<= col; j++){
//            cout << sum[i][j] << " ";
//        }
//        cout << "\n";
//    }

    long long maxSum = 0;
    for(int i = 1; i<= row; i++){
        for(int j = 1 ; j <= col; j++){
            // 1. 2*2 정사각형
            maxSum = max(maxSum, getRectSum(i, j, 2, 2));

            // 2. 4*1, 1*4 직사각형
            maxSum = max(maxSum, getRectSum(i, j, 1, 4));
            maxSum = max(maxSum, getRectSum(i, j, 4, 1));

            // 3-1. z모양 가로
            long long rect = getRectSum(i, j, 2, 3);
            if(rect){
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 2, 1, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 0, 1, 2));
            }

            // 3-2. z모양 세로
            rect = getRectSum(i, j, 3, 2);
            if(rect){
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 1, 2, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 0, 2, 1));
            }

            // 4-1. L모양 가로
            rect = getRectSum(i, j, 2, 3);
            if(rect){
                maxSum = max(maxSum, getTerSum(rect, i, j, 1, 1, 1, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 1, 2, 1, 1));
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 1, 0, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 0, 2, 0, 1));
            }


            // 4-2. L모양 세로
            rect = getRectSum(i, j, 3, 2);
            if(rect){
                maxSum = max(maxSum, getTerSum(rect, i, j, 2, 0, 1, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 2, 1, 1, 1));
                maxSum = max(maxSum, getTerSum(rect, i, j, 1, 0, 0, 0));
                maxSum = max(maxSum, getTerSum(rect, i, j, 1, 1, 0, 1));
            }

            // 5-1. ㅓ 모양 세로
            rect = getRectSum(i, j, 3, 1);
            if(rect && j - 1 >= 1) maxSum = max(maxSum, rect + (long long)arr[i-1][j-1]);
            if(rect && j + 1 <= col) maxSum = max(maxSum, rect + (long long)arr[i-1][j+1]);

            // 5-2. ㅗ 모양 가로
            rect = getRectSum(i, j, 1, 3);
            if(rect && i - 1 >= 1) maxSum = max(maxSum, rect + arr[i-1][j-1]);
            if(rect && i + 1 <= row) maxSum = max(maxSum, rect + arr[i+1][j-1]);

        }
    }


    cout << maxSum << "\n";

}