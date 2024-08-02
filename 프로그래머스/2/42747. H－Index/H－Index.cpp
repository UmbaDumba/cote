#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    if(n < citations[0]){
        // 논문 개수보다 최소 인용개수가 많은경우
        // 무조건 n으로 고정!
        return n;
    }
    
    int hindex = 0;
    for(int i = (n+1)/2; i > 0; i--){
        //cout << i << endl;
        for(int j = citations[i]; j>=citations[i-1]; j--){
            //cout << i << ", "<<j<<endl;
            if((n-i) >= j){
                hindex = max(j, hindex);
                //cout << "Test : "<<hindex<<endl;
                break;
            }
        }
    }
    
    return hindex;
}