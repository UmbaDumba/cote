#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
vector<int> stones;
vector<int> visits;

void steps(int index){
    // [index]로 온 상황
    int left = index - stones[index];
    if(left >= 0 && visits[left] == 0){
        visits[left] = 1;
        steps(left);
    }
    int right = index + stones[index];
    if(right < n && visits[right] == 0){
        visits[right] = 1;
        steps(right);
    }
}

int main(){

    cin >> n;
    visits = vector<int>(n, 0);
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        stones.push_back(temp);
    }
    cin >> s;
    s--; // index

    visits[s] = 1;
    steps(s);

    cout << count(visits.begin(), visits.end(), 1);

    return 0;
}