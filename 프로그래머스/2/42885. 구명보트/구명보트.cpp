#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    /*
    int sum = 0;
    for(int i = 0; i <= people.size() / 2; i++){
        if(people.size() % 2 != 0 && i == people.size() / 2){
            answer++;
        }
        
        int least = people[i];
        int most = people[people.size() - 1 - i];
        
        if(people[least] + people[most] <= limit){
            answer++;
            continue;
        }
        
        answer += people.size() - 2 * i;
        break;
    }*/
    
    int left = 0, right = people.size() - 1, cnt = 0;
    while(left < right){
        if(people[left] + people[right] <= limit){
            cnt += 2;
            answer++;
            left++;
            right--;
            continue;
        }
        cnt++;
        answer++;
        right--;
    }
    answer += people.size() - cnt;
    
    
    return answer;
}