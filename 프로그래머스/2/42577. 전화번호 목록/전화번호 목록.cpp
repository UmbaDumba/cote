#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_set<string> set(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i<phone_book.size(); i++)
    {
        for(int j = 1; j<phone_book[i].size(); j++)
        {
            if(set.find(phone_book[i].substr(0, j)) != set.end())
            {
                // 접두어 있음
                return false;
            }
        }
    }
    
    return true;
}