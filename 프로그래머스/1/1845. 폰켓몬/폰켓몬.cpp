#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_map<int, int> pokets;
    for(int i = 0; i<nums.size(); i++)
    {
        if(pokets.find(nums[i]) == pokets.end())
        {
            answer++;
            pokets[nums[i]] = 1;
        }
        // 개수가 중요하진 않음
        
    }
    
    //cout << answer << endl;
    
    answer = min(answer, ((int)nums.size()) / 2);
    
    return answer;
}