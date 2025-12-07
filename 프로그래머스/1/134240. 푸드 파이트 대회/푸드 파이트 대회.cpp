#include <string>
#include <vector>
using namespace std;

string solution(vector<int> food) {
    string answer = "", firstFood = "";
    for(int i = 1; i< food.size(); i++){
        int cnt = food[i];
        if(cnt % 2 != 0) cnt--;
        for(int j = 0; j < cnt/2; j++) firstFood += to_string(i);
    }
    answer += firstFood + '0';
    
    for(int i = firstFood.size() - 1; i >= 0; i--) answer += firstFood[i];
    return answer;
}