#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> myset;
    
    
    int elesize = (int)elements.size();
    
    for(int i = 1; i<=elesize; i++){
        // 길이가 i인 부분수열 숫자
        for(int j = 0; j<elesize; j++){
            int sum = 0;
            for(int k = 0; k<i; k++){
                sum += elements[(j+k) % elesize];
            }
            myset.insert(sum);
        }
    }
    
    return myset.size();
}