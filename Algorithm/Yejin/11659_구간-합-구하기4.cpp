#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int dp[100001], numbers[100001];
vector<pair<int, int>> questions, sortedQuestions;
int main(){
    cin >> n >> m;
    for(int i = 1; i<= n; i++) cin >> numbers[i];

    dp[1] = numbers[1];

    for(int i = 0; i<m; i++){
        int start, end;
        cin >> start >> end;
        questions.push_back({start, end});
        sortedQuestions.push_back({end, start});
    }
    // 질문 중 가장 큰 값까지만 dp를 안 구하고, 1-n까지 처음에 구해버리면 시간 초과 남.
    sort(sortedQuestions.begin(), sortedQuestions.end());
    for(int i = 2; i<= sortedQuestions[m - 1].first; i++) dp[i] = numbers[i] + dp[i-1];

   for(pair<int, int> question : questions){
       cout << dp[question.second] - dp[question.first - 1] << "\n";
   }

}
