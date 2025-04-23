#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
   
    for(long long i = 1; i<= 5e7; i++){
        long long d = i * i;
        if(d > n) break;
        if(d != n) continue;
        d = (i+1) * (i+1);
        return d;
    }
    return answer;
}