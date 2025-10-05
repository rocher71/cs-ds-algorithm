#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<int, int> m;

int solution(vector<int> nums)
{
    int answer = 0;
    for(int i : nums) m.insert({i, 0});
    
    answer = min(nums.size()/2, m.size());
    
    return answer;
}