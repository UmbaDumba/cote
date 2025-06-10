#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> counts;
    for(int i = 0; i<clothes.size(); i++)
    {
        if(counts.find(clothes[i][1]) == counts.end())
        {
            counts[clothes[i][1]] = 2;
        }else{
            counts[clothes[i][1]]++;
        }
    }
    
    for(auto i = counts.begin(); i != counts.end(); i++)
    {
        answer *= i->second;
    }
    
    return answer - 1;
}