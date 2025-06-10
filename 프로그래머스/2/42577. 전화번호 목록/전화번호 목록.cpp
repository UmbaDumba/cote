#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end());
    
    int compj = 0;
    for(int i = 1; i<phone_book.size(); i++)
    {
        if(phone_book[i].compare(0, phone_book[compj].size(), phone_book[compj]) == 0)
        {
            // 접두어
            return false;
        }else{
            compj = i;
        }
    }
    
    
    return true;
}