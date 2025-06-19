#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <set>

//

using namespace std;

int gem_num;

bool is_all_gem(unordered_map<string, int> counts)
{
    
    if(gem_num == counts.size())
    {
        return true;
    }else{
        return false;
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, 100000};
    
    set<string> keys;
    unordered_map<string, int> counts;
    
    // key dictionary 만들기
    for(int i = 0; i<gems.size(); i++)
    {
        keys.insert(gems[i]);
    }
    
    gem_num = keys.size();
    
    
    int left = 0, right = 0;
    while(1)
    {
        //cout << left << ", "<<right<<endl;
        
        if(gem_num == counts.size())
        {
            if((answer[1] - answer[0]) > (right - 1 - left))
            {
                //cout << "update"<<endl;
                answer = {left+1, right};
            }
            if(counts[gems[left]] > 1){
                counts[gems[left]]--;
                left++;
                continue;
            }
        }
        
        if(right >= gems.size())
        {
            break;
        }
        //cout << "add : "<<gems[right]<<endl;
        if(counts.find(gems[right]) == counts.end())
        {
            counts[gems[right]] = 1;
        }else{
            counts[gems[right]]++;
        }
        
        right++;
    }

  
    return answer;
    
}