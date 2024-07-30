#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> myque(scoville.begin(), scoville.end());
    
    while(true){
        int a1 = myque.top();
        if(a1 >= K){
            break;
        }
        if(myque.size() < 2){
            return -1;
        }
        myque.pop();
        int a2 = myque.top();
        myque.pop();
        
        int newsco = a1 + (a2 * 2);
        myque.push(newsco);
        answer++;
        
    }
    
    return answer;
}