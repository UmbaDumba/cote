#include <iostream>
#include <deque>

using namespace std;


int main(){

    deque<int> que;
    int n;

    cin >> n;

    for(int i = 1; i<=n; i++){
        que.push_back(i);
    }

    while(que.size() != 1){
        que.pop_front();
        int tmp = que.front();
        que.pop_front();
        que.push_back(tmp);
    }

    cout << que.front();
    

    return 0;
}