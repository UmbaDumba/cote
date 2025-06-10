#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_set<int> pokets(nums.begin(), nums.end());
    
    
    //cout << answer << endl;
    
    answer = min(((int)nums.size() / 2), (int)pokets.size());
    
    return answer;
}