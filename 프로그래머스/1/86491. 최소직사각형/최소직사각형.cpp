#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxA = 0, maxB = 0;
    for(int i = 0; i< sizes.size(); i++){
        int a = sizes[i][0];
        int b = sizes[i][1];
        if(a > b){
            sizes[i][0] = b;
            sizes[i][1] = a;
        }
        maxA = max(maxA, sizes[i][0]);
        maxB = max(maxB, sizes[i][1]);
    }
    return maxA * maxB;
}